#include <Arduino.h>
#include "PineTime.h"
#include <lvgl.h>
#include <pinetime40.h>
#include "pinetime_board.h"
#include "ui.h"
#include "ui_events.h"

PineTime pinetime;

void ResetReason() {
  uint32_t reason = readResetReason();

  if (reason & 0x01u) {
    Serial.println("Reset pin");
    return;
  }
  if ((reason >> 1u) & 0x01u) {
    Serial.println("Watchdog");
    return;
  }
  if ((reason >> 2u) & 0x01u) {
    Serial.println("Soft reset");
    return;
  }
  if ((reason >> 3u) & 0x01u) {
    Serial.println("CPU Lock-up");
    return;
  }
  if ((reason >> 16u) & 0x01u) {
    Serial.println("System OFF");
    return;
  }
  if ((reason >> 17u) & 0x01u) {
    Serial.println("LPCOMP");
    return;
  }
  if ((reason)&0x01u) {
    Serial.println("Debug interface");
    return;
  }
  if ((reason >> 19u) & 0x01u) {
    Serial.println("NFC");
    return;
  }
  Serial.println("Hard reset");
}

// ------------------------------------------------------------------------------------------------------------------------

PineTime *PineTime::active_object = 0;

PineTime::PineTime(void) {
  active_object = this;
}

void PineTime::updateScreen(void (*function)(void)) {
  _updateScreen = function;
}

void PineTime::begin(void) {
  Serial.println("# PineTime nRF52840 Starting.");
  Serial.println("");
  while (!Serial) delay(100);

  Serial.print("> Last reset reason : ");
  ResetReason();

  Serial.println("> Watchdog init");
  watchdog_init(5000);

  init_i2c();

  Serial.println("> BLE Init");
  bluetoothInit();

  Serial.println("> Backlight init");
  backlight.init();
  backlight.set_value_fast(20);

  Serial.println("> Display init");
  init_display();

  Serial.println("> RTC init");
  rtctime.init();
  rtctime.get_time();

  Serial.println("> Touch init");
  touch.init();

  Serial.println("> Power button init");
  powerButtonInit();

  Serial.println("> Charging status init");
  chargingStatusInit();

  readBatteryStatus();
  showDebugBattStatus();

  Serial.println("> LVGL init");
  lv_init();
  lvglInitDrivers();

  Serial.println("> UI init");
  ui_init();

  Serial.println("> Pinetime hardware started...");

  pinetime.backlight.set_value(80);

  // Init work timers
  initWorkTimers();

  // Subscribe to system message
  systemMessages();
}

void PineTime::loop(void) {
  
  lv_timer_handler();

  if ( state == States::Running ) { 
    old_sleep = lv_disp_get_inactive_time(lv_disp_get_default());
    if (old_sleep > SW_SLEEP_MS) {
      backlight.dim();
      if (old_sleep > SW_SLEEP_MS * 2) {
        goToSleep();
      }
    } else {      
      backlight.restore_dim();
    }
  }
  watchdog_feed();
}
// ------------------------------------------------------------------------------------------------------------------------
/*
  Sleep functions
*/

void PineTime::wakeUp(void) {
  if ( state == States::Running ) return;
  state = States::Running;
  lv_timer_handler();
  lv_disp_trig_activity(NULL);
  displayWakeUp();  
  Serial.println("# >>> Waking up.");
}

void PineTime::goToSleep(void) {
  if ( state == States::Idle ) return;  
  pinetime.backlight.set_value(0);
  displaySleep();
  Serial.println("# >>> Going to sleep.");
  state = States::Idle;
}

// ------------------------------------------------------------------------------------------------------------------------
/*
  System message functions
*/
#define MSG_POWER_BUTTON    0x01
#define MSG_CHARGING        0x02

inline void PineTime::powerButtonCB(lv_msg_t * m) {  
  //lv_msg_get_user_data(m)
  //lv_msg_get_payload(m)
  Serial.println("# >>> Power button from sysmsg...");
  if (active_object) {
    //active_object->nnnn();
    if ( active_object->state == States::Idle ) {
      active_object->wakeUp();
    }
  }
}

inline void PineTime::chargingStatusCB(lv_msg_t * m) {
  //lv_msg_get_user_data(m)
  //lv_msg_get_payload(m)
  Serial.println("# >>> Charging status from sysmsg...");
  Serial.printf("# >>> Charging status : %s \n", active_object->isCharging ? "Charging" : "Discharging");
  if (active_object) {
    //active_object->nnnn();
  }
}

void PineTime::systemMessages(void) {
  lv_msg_subscribe(MSG_POWER_BUTTON, PineTime::powerButtonCB, NULL);
  lv_msg_subscribe(MSG_CHARGING, PineTime::chargingStatusCB, NULL);
}

// ------------------------------------------------------------------------------------------------------------------------
/*
  Work timers functions
*/

void PineTime::callUpdateScreen(void) {
  // call update screen callback if provided
  if (_updateScreen) {
    _updateScreen();
  }
}

inline void PineTime::callUpdateScreenCB(lv_timer_t *timer) {
  if (active_object) {
    active_object->callUpdateScreen();
  }
}

void stopTimerCallback(TimerHandle_t xTimer) {
  xTimerStop(xTimer, 0);
}

void PineTime::initWorkTimers(void) {
  buttonTimer = xTimerCreate("buttonTimer", 300, pdFALSE, NULL, stopTimerCallback);
  timerUpdateScreen = lv_timer_create(callUpdateScreenCB, 1000, NULL);
  statusWorkTimer();
}

void PineTime::readStatus(void) {
  readBatteryStatus();
  showDebugBattStatus();

  callUpdateScreen();

  if (bleConnected) {
    bleSendBattery();
  }
}

inline void PineTime::readStatusCB(TimerHandle_t xTimer) {
  if (active_object) {
    active_object->readStatus();
  }
}

void PineTime::statusWorkTimer(void) {
  timerStatus.begin(60000, PineTime::readStatusCB);
  timerStatus.start();
}

// ------------------------------------------------------------------------------------------------------------------------
/*
  Power functions
*/

inline void PineTime::powerButtonHandler(void) {
  if (active_object) {

    if (xTimerIsTimerActive(active_object->buttonTimer) == pdFALSE) {
      BaseType_t xHigherPriorityTaskWoken = pdFALSE;
      xTimerStartFromISR(active_object->buttonTimer, &xHigherPriorityTaskWoken);
      //Serial.println("# Power button pressed...");
      lv_msg_send(MSG_POWER_BUTTON, NULL);
    }

  }
}

void PineTime::powerButtonInit(void) {
  pinMode(PIN_BUTTON1, INPUT_PULLUP);
  attachInterrupt(PIN_BUTTON1, PineTime::powerButtonHandler, ISR_DEFERRED | FALLING);
  //Serial.printf("## BT status : %i \n", digitalRead(PIN_BUTTON1));
}

// ------------------------------------------------------------------------------------------------------------------------
/*
  Charging functions
*/

inline void PineTime::chargingStatusHandler(void) {
  if (active_object) {

    if (xTimerIsTimerActive(active_object->buttonTimer) == pdFALSE) {
      BaseType_t xHigherPriorityTaskWoken = pdFALSE;
      xTimerStartFromISR(active_object->buttonTimer, &xHigherPriorityTaskWoken);
      //Serial.printf(">> Charging status : %s \n", active_object->isCharging ? "Charging" : "Discharging");
      lv_msg_send(MSG_CHARGING, NULL);
    }

  }
}

void PineTime::chargingStatusInit(void) {
  pinMode(PIN_CHARGE_IRQ, INPUT_PULLUP);
  isCharging = !digitalRead(PIN_CHARGE_IRQ);
  attachInterrupt(PIN_CHARGE_IRQ, chargingStatusHandler, CHANGE);
  //Serial.printf(">> Charging status : %s \n", isCharging ? "Charging" : "Discharging");
}

// ------------------------------------------------------------------------------------------------------------------------
/*
  Battery functions
*/
float PineTime::readVBAT(void) {
  float raw;

  // Set the analog reference to 3.0V (default = 3.6V)
  analogReference(AR_INTERNAL_3_0);

  // Set the resolution to 12-bit (0..4095)
  analogReadResolution(12);  // Can be 8, 10, 12 or 14

  // Let the ADC settle
  delay(1);

  // Get the raw 12-bit, 0..3000mV ADC value
  raw = analogRead(PIN_A0);

  // Set the ADC back to the default settings
  analogReference(AR_DEFAULT);
  analogReadResolution(10);

  // Convert the raw value to compensated mv, taking the resistor-
  // divider into account (providing the actual LIPO voltage)
  // ADC range is 0..3000mV and resolution is 12-bit (0..4095)
  return raw * REAL_VBAT_MV_PER_LSB;
}

uint8_t PineTime::mvToPercent(float mvolts) {

  float output = 0.0;
  output = map(mvolts, 3300, 4200, 0, 100);
  output = constrain(output, 0, 100);

  return output;
}

void PineTime::readBatteryStatus(void) {
  // Get a single ADC sample and throw it away
  readVBAT();
  // Get a raw ADC reading
  vbat_mv = readVBAT();
  // Convert from raw mv to percentage (based on LIPO chemistry)
  vbat_per = mvToPercent(vbat_mv);
  isCharging = !digitalRead(PIN_CHARGE_IRQ);
}

void PineTime::showDebugBattStatus(void) {
  Serial.println("> Vbatt status");
  Serial.print(">> LIPO = ");
  Serial.print(vbat_mv);
  Serial.print(" mV (");
  Serial.print(vbat_per);
  Serial.println("%)");
  Serial.printf(">> Charging status : %s \n", isCharging ? "Charging" : "Discharging");
}

// ------------------------------------------------------------------------------------------------------------------------
/*
  LVGL functions
*/

/* Display flushing */
inline void PineTime::dispFlush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {

  uint32_t width = (area->x2 - area->x1) + 1;
  uint32_t height = (area->y2 - area->y1) + 1;

  swapBytes((uint16_t *)color_p, (width * height));

  draw_buffer(area->x1, area->y1, width, height, (uint8_t *)color_p);

  lv_disp_flush_ready(disp_drv);
}

/*Read the touchpad*/
inline void PineTime::touchpadRead(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {

  if (active_object) {
    active_object->touch.get();

    bool touched = active_object->touch.getEvent() == 1 ? 1 : 0;

    if (!touched) {
      data->state = LV_INDEV_STATE_REL;
    } else {
      data->state = LV_INDEV_STATE_PR;

      //Set the coordinates
      data->point.x = active_object->touch.getX();
      data->point.y = active_object->touch.getY();
    }
  }
}

void PineTime::lvglInitDrivers(void) {
  Serial.println("> LVGL display init");
  lv_disp_draw_buf_init(&draw_buf, buf_1, NULL, screenWidth * SCREEN_BUFFER_SIZE);

  //Initialize the display
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  //Change the following line to your display resolution
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = PineTime::dispFlush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  //Initialize the input device driver
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = PineTime::touchpadRead;
  lv_indev_drv_register(&indev_drv);
}
// ------------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------------------
/*
  Bluetooth message functions
*/

#define COMMAND_BASE 0x00
#define COMMAND_TIME_UPDATE COMMAND_BASE + 0x01
#define COMMAND_NOTIFICATION COMMAND_BASE + 0x02
#define COMMAND_DELETE_NOTIFICATION COMMAND_BASE + 0x03
#define COMMAND_SET_ALARMS COMMAND_BASE + 0x04
#define COMMAND_SET_CALL COMMAND_BASE + 0x05
#define COMMAND_SET_MUSIC COMMAND_BASE + 0x06
#define COMMAND_SET_MUSIC_INFO COMMAND_BASE + 0x07
#define COMMAND_ACTIVITY_STATUS COMMAND_BASE + 0x08
#define COMMAND_FIND_DEVICE COMMAND_BASE + 0x09
#define COMMAND_VIBRATION COMMAND_BASE + 0x0a
#define COMMAND_WEATHER COMMAND_BASE + 0x0b
#define COMMAND_STATUS COMMAND_BASE + 0x0c

#define COMMAND_PT_VERSION COMMAND_BASE + 0x01
#define COMMAND_PT_BATTERY COMMAND_BASE + 0x02
#define COMMAND_PT_STEPS COMMAND_BASE + 0x03
#define COMMAND_PT_HEARTRATE COMMAND_BASE + 0x04

// ------------------------------------------------------------------------------------------------------------------------

int packFloat(void *buf, float x) {
  unsigned char *b = (unsigned char *)buf;
  unsigned char *p = (unsigned char *)&x;
  b[0] = p[3];
  b[1] = p[2];
  b[2] = p[1];
  b[3] = p[0];
  return 4;
}

int packInt(void *buf, int x) {
  unsigned char *b = (unsigned char *)buf;
  unsigned char *p = (unsigned char *)&x;
  b[0] = p[3];
  b[1] = p[2];
  b[2] = p[1];
  b[3] = p[0];
  return 4;
}

int packByte(void *buf, uint8_t x) {
  unsigned char *b = (unsigned char *)buf;
  unsigned char *p = (unsigned char *)&x;
  b[0] = p[0];
  return 1;
}

float round_to_dp(float in_value, int decimal_place) {
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}

uint32_t PineTime::getUartInt(void) {
  return bleuart.read8() << 24 | bleuart.read8() << 16 | bleuart.read8() << 8 | bleuart.read8();
}

uint8_t PineTime::getUartByte(void) {
  return bleuart.read8();
}

// ------------------------------------------------------------------------------------------------------------------------

void PineTime::bleuartSendData(const uint8_t *content, size_t len) {
  bleuart.write(content, len);
}

void PineTime::bleSendVersion(void) {
  uint8_t data[4] = {
    0x00,
    COMMAND_PT_VERSION,
    0x00,
    0x01
  };
  bleuartSendData(data, 4);
}

void PineTime::bleSendBattery(void) {

  uint8_t data[11] = {};
  uint8_t status = 0;

  //status = 0x01; // Error
  //status = 0x02;  // charging
  status = 0x03;  // normal

  if (isCharging) {
    status = 0x02;
  }

  uint8_t i = 0;
  data[i++] = 0x00;
  data[i++] = COMMAND_PT_BATTERY;

  i += packInt(&data[i], vbat_per);
  i += packFloat(&data[i], round_to_dp((vbat_mv / 1000), 3));
  i += packByte(&data[i], status);

  bleuartSendData(data, i);
}

void PineTime::bleDecodeMessage(uint8_t msgType, int16_t msgSize) {
  switch (msgType) {
    case COMMAND_TIME_UPDATE:
      Serial.println(">>BL MSG : COMMAND_TIME_UPDATE");
      if (msgSize == 4) {
        rtctime.set_time(getUartInt());
        //backlight.restore_dim();
      }
      break;

    case COMMAND_STATUS:
      Serial.println(">>BL MSG : COMMAND_STATUS");
      //bleSendVersion();
      bleSendBattery();
      break;

    case COMMAND_NOTIFICATION:
      Serial.println(">>BL MSG : COMMAND_NOTIFICATION");
      break;

    case COMMAND_DELETE_NOTIFICATION:
      Serial.println(">>BL MSG : COMMAND_DELETE_NOTIFICATION");
      break;

    case COMMAND_WEATHER:
      Serial.println(">>BL MSG : COMMAND_WEATHER");
      break;

    case COMMAND_FIND_DEVICE:
      Serial.println(">>BL MSG : COMMAND_FIND_DEVICE");
      break;

    case COMMAND_VIBRATION:
      Serial.println(">>BL MSG : COMMAND_VIBRATION");
      break;

    default:
      Serial.print(">>BL MSG : unknown (");
      Serial.print(msgType);
      Serial.print(")");
      break;
  }
}

void PineTime::rxDecode(void) {
  if (inputEnd == 1 && bleuart.read8() == COMMAND_BASE) {
    inputEnd = 0;
    msgType = bleuart.read8();
    msgSize = bleuart.read16();
  }

  if (bleuart.available() >= msgSize && inputEnd == 0) {

    bleDecodeMessage(msgType, msgSize);

    bleuart.flush();
    inputEnd = 1;
    msgSize = 0;
    msgType = 0;
  }
}

// ------------------------------------------------------------------------------------------------------------------------
/*
  Bluetooth functions
*/


// Invoked when receiving data from bleuart
inline void PineTime::bleuartRXcallback(uint16_t conn_hdl) {
  (void)conn_hdl;
  if (active_object) {
    active_object->rxDecode();
  }
}

// callback invoked when central connects
inline void PineTime::connectCallback(uint16_t conn_handle) {
  // Get the reference to current connection
  BLEConnection *connection = Bluefruit.Connection(conn_handle);

  char central_name[32] = { 0 };
  connection->getPeerName(central_name, sizeof(central_name));

  Serial.print(">>BL Connected to ");
  Serial.println(central_name);

  // request PHY changed to 2MB
  Serial.println(">>BL Request to change PHY");
  connection->requestPHY();

  // request to update data length
  Serial.println(">>BL Request to change Data Length");
  connection->requestDataLengthUpdate();

  // request mtu exchange
  //Serial.println(">>BL Request to change MTU");
  //connection->requestMtuExchange(247);
  active_object->bleSetStatus(true);
}

// Callback invoked when a connection is dropped
inline void PineTime::disconnectCallback(uint16_t conn_handle, uint8_t reason) {
  (void)conn_handle;
  (void)reason;

  Serial.println();
  Serial.printf(">>BL Disconnected, reason = 0x%02X (%s)", reason, dbg_hci_str(reason));
  Serial.println();
  active_object->bleSetStatus(false);
}

void PineTime::bluetoothStartAdvertising(void) {
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  // Include bleuart 128-bit uuid
  Bluefruit.Advertising.addService(bleuart);

  // Secondary Scan Response packet (optional)
  // Since there is no room for 'Name' in Advertising packet
  Bluefruit.ScanResponse.addName();

  //* Start Advertising
  //   * - Enable auto advertising if disconnected
  //   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
  //   * - Timeout for fast mode is 30 seconds
  //   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
  //   *
  //   * For recommended advertising interval
  //   * https://developer.apple.com/library/content/qa/qa1931/_index.html

  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);  // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);    // number of seconds in fast mode
  Bluefruit.Advertising.start(0);              // 0 = Don't stop advertising after n seconds
}

void PineTime::bluetoothInit(void) {
  Bluefruit.begin();
  Bluefruit.setName("Pinetime Arduino");
  Bluefruit.setAppearance(BLE_APPEARANCE_GENERIC_WATCH);
  Bluefruit.setTxPower(4);  // Check bluefruit.h for supported values
  Bluefruit.Periph.setConnectCallback(PineTime::connectCallback);
  Bluefruit.Periph.setDisconnectCallback(PineTime::disconnectCallback);

  //Serial.println(">>BL Setting pairing PIN to: " PAIRING_PIN);
  //Bluefruit.Security.setPIN(PAIRING_PIN);
  // Set connection secured callback, invoked when connection is encrypted
  //Bluefruit.Security.setSecuredCallback(connection_secured_callback);

  // To be consistent OTA DFU should be added first if it exists
  //bledfu.begin();

  // Configure and Start Device Information Service
  bledis.setManufacturer("joaquim.org");
  bledis.setModel("Pinetime");
  bledis.begin();

  // Configure and Start BLE Uart Service
  bleuart.setRxCallback(PineTime::bleuartRXcallback, true);
  bleuart.bufferTXD(false);
  // Set Permission to access BLE Uart is to require man-in-the-middle protection
  // This will cause central to perform pairing with static PIN we set above
  bleuart.setPermission(SECMODE_ENC_WITH_MITM, SECMODE_ENC_WITH_MITM);
  bleuart.begin();

  // Start BLE Battery Service
  //blebas.begin();
  //blebas.write(100);

  // Set up and start advertising
  bluetoothStartAdvertising();
}
