#include <stdlib.h>
#include <math.h>

#include <lvgl.h>
#include <pinetime40.h>
#include "pinetime_board.h"
#include "ui.h"
#include "ui_events.h"

//#include <Wire.h>
#include <bluefruit.h>
//#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>
//#include "flash/flash_nrf5x.h"

typedef volatile uint32_t REG32;
#define pREG32 (REG32 *)

#define DEVICE_ID_HIGH (*(pREG32(0x10000060)))
#define DEVICE_ID_LOW (*(pREG32(0x10000064)))

using namespace Adafruit_LittleFS_Namespace;

#define MAX_LEVEL 2

// BLE Service
//BLEDfu  bledfu;  // OTA DFU service
BLEDis bledis;    // device information
BLEUart bleuart;  // uart over ble
//BLEBas blebas;    // battery

static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
#define SCREEN_BUFFER_SIZE 80
static lv_color_t buf_1[screenWidth * SCREEN_BUFFER_SIZE];
//static lv_color_t buf_2[screenWidth * SCREEN_BUFFER_SIZE];

Touch touch;
RTCTime rtctime;
Backlight backlight;

uint32_t old_sleep = 0;

/* Display flushing */
static void pt_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {

  uint32_t width = (area->x2 - area->x1) + 1;
  uint32_t height = (area->y2 - area->y1) + 1;

  swapBytes((uint16_t *)color_p, (width * height));

  draw_buffer(area->x1, area->y1, width, height, (uint8_t *)color_p);

  lv_disp_flush_ready(disp_drv);
}

/*Read the touchpad*/
void pt_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {

  touch.get();

  bool touched = touch.getEvent() == 1 ? 1 : 0;

  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
    data->state = LV_INDEV_STATE_PR;

    //Set the coordinates
    data->point.x = touch.getX();
    data->point.y = touch.getY();

    /*Serial.print("touch : ");
    Serial.print(data->point.x);
    Serial.print(" - ");
    Serial.print(data->point.y);
    Serial.println();*/
  }
  //data->state = LV_INDEV_STATE_REL;
}
// ---------------------------------------------------------------------------------------------------------------------------------

void lvgl_drv_init(void) {
  Serial.println("> LVGL display init");
  lv_disp_draw_buf_init(&draw_buf, buf_1, NULL, screenWidth * SCREEN_BUFFER_SIZE);

  //Initialize the display
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  //Change the following line to your display resolution
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = pt_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  //Initialize the input device driver
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = pt_touchpad_read;
  lv_indev_drv_register(&indev_drv);
}

// ---------------------------------------------------------------------------------------------------------------------------------

float vbat_mv = 0.0;
uint8_t vbat_per = 0;
bool is_charging = false;

// ---------------------------------------------------------------------------------------------------------------------------------

#define HYSTERESIS_MS 20
unsigned long lastPress = 0;

void power_button_handler() {
  unsigned long ms = millis();
  if ((ms - lastPress > HYSTERESIS_MS) && !digitalRead(PIN_BUTTON1)) {
    goto_home();
    Serial.println("# Power button pressed...");
    //Serial.printf("## Button status : %i \n", digitalRead(PIN_BUTTON1));
  }
  lastPress = ms;
}

void power_button_init(void) {
  pinMode(PIN_BUTTON1, INPUT_PULLUP);
  attachInterrupt(PIN_BUTTON1, power_button_handler, ISR_DEFERRED | FALLING);
  //Serial.printf("## BT status : %i \n", digitalRead(PIN_BUTTON1));
}
// ---------------------------------------------------------------------------------------------------------------------------------
void goto_charging();

void charging_handler() {
  is_charging = !digitalRead(PIN_CHARGE_IRQ);

  Serial.printf("## New Charging status : %i \n", is_charging);

  if (is_charging) {
    goto_charging();
  }
}

void charging_init(void) {  
  pinMode(PIN_CHARGE_IRQ, INPUT_PULLUP);
  is_charging = !digitalRead(PIN_CHARGE_IRQ);
  attachInterrupt(PIN_CHARGE_IRQ, charging_handler, CHANGE);
  //Serial.printf("## Charging status : %i \n", is_charging);
}
// ---------------------------------------------------------------------------------------------------------------------------------

#define VBAT_MV_PER_LSB (0.73242188F)  // 3.0V ADC range and 12-bit ADC resolution = 3000mV/4096

#define VBAT_DIVIDER (0.50F)       // 1M + 1M voltage divider on VBAT = (1M / (1M + 1M))
#define VBAT_DIVIDER_COMP (2.05F)  // Compensation factor for the VBAT divider

#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)

float readVBAT(void) {
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

uint8_t mvToPercent(float mvolts) {

  float output = 0.0;
  output = map(mvolts, 3300, 4200, 0, 100);
  output = constrain(output, 0, 100);

  return output;
}

void read_batt_status() {

  // Get a single ADC sample and throw it away
  readVBAT();

  // Get a raw ADC reading
  vbat_mv = readVBAT();

  // Convert from raw mv to percentage (based on LIPO chemistry)
  vbat_per = mvToPercent(vbat_mv);

  is_charging = !digitalRead(PIN_CHARGE_IRQ);
}

void show_batt_status() {
  // Display the results
  Serial.println();
  Serial.println("> Vbatt status");
  Serial.print("## LIPO = ");
  Serial.print(vbat_mv);
  Serial.print(" mV (");
  Serial.print(vbat_per);
  Serial.println("%)");

  Serial.printf("## Charging status : %i \n", is_charging);
  Serial.println();
  Serial.println();
}

void get_batt_icon() {
  if (is_charging) {
    lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
    //lv_label_set_text_fmt(ui_BattIcon5, "");
    lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0xFFFF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  } else {
    if (vbat_per < 10) {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    } else if (vbat_per < 25) {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0xFFFF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    } else if (vbat_per < 50) {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    } else if (vbat_per < 85) {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    } else {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
  }
}


void ble_send_battery(void);

static void read_status(TimerHandle_t xTimer) {
  read_batt_status();
  show_batt_status();
  ble_send_battery();
  lv_label_set_text_fmt(ui_ConfigBatt, "%d%%", vbat_per);
  get_batt_icon();
}

// ---------------------------------------------------------------------------------------------------------------------------------

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

SoftwareTimer statusTimer;

void init_watch() {

  Serial.print("> Reset Reason : ");
  ResetReason();

  Serial.println("> Watchdog init");
  watchdog_init(5000);

  init_i2c();

  Serial.println("> Display init");
  init_display();

  Serial.println("> RTC init");
  rtctime.init();
  rtctime.get_time();

  Serial.println("> Touch init");
  touch.init();
  Serial.println("> Touch ready");

  Serial.println("> Power button init");
  power_button_init();

  Serial.println("> Charging status init");
  charging_init();

  read_batt_status();
  show_batt_status();

  statusTimer.begin(60000, read_status);
  statusTimer.start();
}

// ---------------------------------------------------------------------------------------------------------------------------------

void _quick_setings(lv_event_t *e) {
  lv_label_set_text_fmt(ui_ConfigBatt, "%d%%", vbat_per);
  get_batt_icon();
}


void _charging_load(lv_event_t *e) {
  read_batt_status();

  get_batt_icon();

  lv_label_set_text_fmt(ui_BattStatus, "%.2f V", vbat_mv / 1000);

  lv_label_set_text_fmt(ui_BattPerc, "%d%%", vbat_per);
  lv_arc_set_value(ui_BattLvl, vbat_per);

}


uint8_t old_min = 99;
uint8_t old_min_c = 99;
uint8_t old_hour = 99;
uint8_t old_day = 99;

void goto_home() {
  lv_obj_t *curr_screen = lv_scr_act();

  if (curr_screen == NULL) {
    return;
  }
  if (curr_screen != ui_Clock) {
    lv_scr_load_anim(ui_Clock, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 0, 0, false);
  }
}

void goto_charging() {
  lv_obj_t *curr_screen = lv_scr_act();

  if (curr_screen == NULL) {
    return;
  }
  if (curr_screen != ui_Charging) {
    lv_scr_load_anim(ui_Charging, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 0, 0, false);
  }
}

void update_day() {
  lv_obj_set_style_text_color(ui_Clock_wd1, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd2, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd3, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd4, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd5, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd6, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd7, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);

  switch (rtctime.week()) {
    case 6:
      lv_obj_set_style_text_color(ui_Clock_wd1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_y(ui_Clock_dot, -83);
      break;
    case 0:
      lv_obj_set_style_text_color(ui_Clock_wd2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_y(ui_Clock_dot, -55);
      break;
    case 1:
      lv_obj_set_style_text_color(ui_Clock_wd3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_y(ui_Clock_dot, -27);
      break;
    case 2:
      lv_obj_set_style_text_color(ui_Clock_wd4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_y(ui_Clock_dot, 2);
      break;
    case 3:
      lv_obj_set_style_text_color(ui_Clock_wd5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_y(ui_Clock_dot, 31);
      break;
    case 4:
      lv_obj_set_style_text_color(ui_Clock_wd6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_y(ui_Clock_dot, 60);
      break;
    case 5:
      lv_obj_set_style_text_color(ui_Clock_wd7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_y(ui_Clock_dot, 87);
      break;
  }
}

void update_clock() {

  lv_obj_t *curr_screen = lv_scr_act();

  if (curr_screen == NULL) {
    return;
  }

  rtctime.get_time();

  if (curr_screen == ui_Clock) {
    if (old_min != rtctime.minutes()) {
      lv_label_set_text_fmt(ui_Clock_Minute, "%02i", rtctime.minutes());
      old_min = rtctime.minutes();
    }
    if (old_hour != rtctime.hours()) {
      lv_label_set_text_fmt(ui_Clock_Hour, "%02i", rtctime.hours());
      old_hour = rtctime.hours();
    }
    if (old_day != rtctime.week()) {
      update_day();
      old_day = rtctime.week();
    }
  } else if (curr_screen == ui_Config) {
    if (old_min_c != rtctime.minutes()) {
      lv_label_set_text_fmt(ui_Config_Time, "%02i:%02i", rtctime.hours(), rtctime.minutes());
      old_min_c = rtctime.minutes();
    }
  } else {
    old_min = 99;
    old_min_c = 99;
    old_hour = 99;
    old_day = 99;
  }
}

void update_time_cb(lv_timer_t *timer) {
  update_clock();
}

void _set_backlight(lv_event_t *e) {
  lv_obj_t *target = lv_event_get_target(e);
  backlight.set_value_fast((int)lv_arc_get_value(target));
  lv_label_set_text_fmt(ui_Backlight_Value, "%d%%", backlight.get_value() * 100 / 128);
}

// ---------------------------------------------------------------------------------------------------------------------------------

void _set_bl_value(lv_event_t *e) {
  //lv_arc_set_value(ui_Backlight_Select, backlight.get_value());
}


// ---------------------------------------------------------------------------------------------------------------------------------

void run() {

  update_clock();

  lv_timer_t *timer = lv_timer_create(update_time_cb, 1000, NULL);

  backlight.set_value(100);
  lv_arc_set_value(ui_Backlight_Select, 100);
  lv_label_set_text_fmt(ui_Backlight_Value, "%d%%", 100 * 100 / 128);
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

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

#define COMMAND_PT_VERSION COMMAND_BASE + 0x01
#define COMMAND_PT_BATTERY COMMAND_BASE + 0x02
#define COMMAND_PT_STEPS COMMAND_BASE + 0x03
#define COMMAND_PT_HEARTRATE COMMAND_BASE + 0x04


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

void send_data_ble(const uint8_t *content, size_t len) {
  bleuart.write(content, len);
}

void ble_send_version(void) {
  uint8_t data[4] = {
    0x00,
    COMMAND_PT_VERSION,
    0x00,
    0x01
  };
  send_data_ble(data, 4);
}

float round_to_dp(float in_value, int decimal_place) {
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}

void ble_send_battery(void) {

  uint8_t data[11] = {};
  uint8_t status = 0;


  //status = 0x01; // Error
  //status = 0x02;  // charging
  status = 0x03;  // normal

  if (is_charging) {
    status = 0x02;
  }


  uint8_t i = 0;
  data[i++] = 0x00;
  data[i++] = COMMAND_PT_BATTERY;

  i += packInt(&data[i], vbat_per);
  i += packFloat(&data[i], round_to_dp((vbat_mv / 1000), 3));
  i += packByte(&data[i], status);

  send_data_ble(data, i);
}

static uint32_t get_int() {
  return bleuart.read8() << 24 | bleuart.read8() << 16 | bleuart.read8() << 8 | bleuart.read8();
}

static uint8_t get_byte() {
  return bleuart.read8();
}

void decode_message(uint8_t msgType, int16_t msgSize) {
  switch (msgType) {
    case COMMAND_TIME_UPDATE:
      if (msgSize == 4) {
        rtctime.set_time(get_int());
        old_min = 99;
        //backlight.restore_dim();
      }
      ble_send_version();
      ble_send_battery();
      break;

    case COMMAND_NOTIFICATION:
      bleuart.flush();
      break;

    case COMMAND_DELETE_NOTIFICATION:
      bleuart.flush();
      break;

    case COMMAND_WEATHER:
      bleuart.flush();
      break;

    case COMMAND_FIND_DEVICE:
      bleuart.flush();
      break;

    case COMMAND_VIBRATION:
      bleuart.flush();
      break;

    default:
      bleuart.flush();
      break;
  }
}

uint16_t countrx = 0;
uint8_t inputEnd = 1;

int16_t msgSize = 0;
uint8_t msgType = 0;

// Invoked when receiving data from bleuart
void bleuart_rx_callback(uint16_t conn_hdl) {
  (void)conn_hdl;

  if (inputEnd == 1 && bleuart.read8() == COMMAND_BASE) {
    inputEnd = 0;
    msgType = bleuart.read8();
    msgSize = bleuart.read16();
  }

  if (bleuart.available() >= msgSize && inputEnd == 0) {

    decode_message(msgType, msgSize);

    bleuart.flush();
    inputEnd = 1;
    msgSize = 0;
    msgType = 0;
  }
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// callback invoked when central connects
void connect_callback(uint16_t conn_handle) {
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


  delay(1000);
}

// Callback invoked when a connection is dropped
void disconnect_callback(uint16_t conn_handle, uint8_t reason) {
  (void)conn_handle;
  (void)reason;

  Serial.println();
  Serial.printf(">>BL Disconnected, reason = 0x%02X (%s)", reason, dbg_hci_str(reason));
  Serial.println();
}


void connection_secured_callback(uint16_t conn_handle) {
  BLEConnection *conn = Bluefruit.Connection(conn_handle);

  if (!conn->secured()) {
    // It is possible that connection is still not secured by this time.
    // This happens (central only) when we try to encrypt connection using stored bond keys
    // but peer reject it (probably it remove its stored key).
    // Therefore we will request an pairing again --> callback again when encrypted
    conn->requestPairing();
  } else {
    Serial.println(">>BL Secured");
  }
}

void startAdv(void) {
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

// Static PIN is 6 digits from 000000-999999
#define PAIRING_PIN "123456"

void bl_init() {
  // -------------------------------------------------

  Bluefruit.begin();
  Bluefruit.setName("Pinetime Arduino");
  Bluefruit.setAppearance(BLE_APPEARANCE_GENERIC_WATCH);
  Bluefruit.setTxPower(4);  // Check bluefruit.h for supported values
  Bluefruit.Periph.setConnectCallback(connect_callback);
  Bluefruit.Periph.setDisconnectCallback(disconnect_callback);

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
  bleuart.setRxCallback(bleuart_rx_callback, true);
  bleuart.bufferTXD(false);
  // Set Permission to access BLE Uart is to require man-in-the-middle protection
  // This will cause central to perform pairing with static PIN we set above
  bleuart.setPermission(SECMODE_ENC_WITH_MITM, SECMODE_ENC_WITH_MITM);
  bleuart.begin();

  // Start BLE Battery Service
  //blebas.begin();
  //blebas.write(100);

  // Set up and start advertising
  startAdv();
}

// ---------------------------------------------------------------------------------------------------------------------------------

/**************************************************************************/
/*!
    @brief  Print out whole directory tree of an folder
            until the level reach MAX_LEVEL

    @note   Recursive call
*/
/**************************************************************************/

void printTreeDirInt(const char *cwd, uint8_t level) {
  // Open the input folder
  Adafruit_LittleFS_Namespace::File dir(cwd, Adafruit_LittleFS_Namespace::FILE_O_READ, InternalFS);

  // Print root
  if (level == 0) Serial.println("root");

  // File within folder
  Adafruit_LittleFS_Namespace::File item(InternalFS);

  // Loop through the directory
  while ((item = dir.openNextFile(Adafruit_LittleFS_Namespace::FILE_O_READ))) {
    // Indentation according to dir level
    for (int i = 0; i < level; i++) Serial.print("|  ");

    Serial.print("|_ ");
    Serial.print(item.name());

    if (item.isDirectory()) {
      Serial.println("/");

      // ATTENTION recursive call to print sub folder with level+1 !!!!!!!!
      // High number of MAX_LEVEL can cause memory overflow
      if (level < MAX_LEVEL) {
        char dpath[strlen(cwd) + strlen(item.name()) + 2];
        strcpy(dpath, cwd);
        strcat(dpath, "/");
        strcat(dpath, item.name());

        printTreeDirInt(dpath, level + 1);
      }
    } else {
      // Print file size starting from position 30
      int pos = level * 3 + 3 + strlen(item.name());

      // Print padding
      for (int i = pos; i < 30; i++) Serial.print(' ');

      // Print at least one extra space in case current position > 50
      Serial.print(' ');

      Serial.print(item.size());
      Serial.println(" Bytes");
    }

    item.close();
  }

  dir.close();
}


void printTreeDir(const char *cwd, uint8_t level) {
  // Open the input folder
  Adafruit_LittleFS_Namespace::File dir(cwd, Adafruit_LittleFS_Namespace::FILE_O_READ, ExternalFS);

  // Print root
  if (level == 0) Serial.println("root");

  // File within folder
  Adafruit_LittleFS_Namespace::File item(ExternalFS);

  // Loop through the directory
  while ((item = dir.openNextFile(Adafruit_LittleFS_Namespace::FILE_O_READ))) {
    // Indentation according to dir level
    for (int i = 0; i < level; i++) Serial.print("|  ");

    Serial.print("|_ ");
    Serial.print(item.name());

    if (item.isDirectory()) {
      Serial.println("/");

      // ATTENTION recursive call to print sub folder with level+1 !!!!!!!!
      // High number of MAX_LEVEL can cause memory overflow
      if (level < MAX_LEVEL) {
        char dpath[strlen(cwd) + strlen(item.name()) + 2];
        strcpy(dpath, cwd);
        strcat(dpath, "/");
        strcat(dpath, item.name());

        printTreeDir(dpath, level + 1);
      }
    } else {
      // Print file size starting from position 30
      int pos = level * 3 + 3 + strlen(item.name());

      // Print padding
      for (int i = pos; i < 30; i++) Serial.print(' ');

      // Print at least one extra space in case current position > 50
      Serial.print(' ');

      Serial.print(item.size());
      Serial.println(" Bytes");
    }

    item.close();
  }

  dir.close();
}

// ---------------------------------------------------------------------------------------------------------------------------------

#define FILENAME "/boot.txt"
#define CONTENTS "Pinetime 40 BOOT"

void setup() {

  Serial.begin(115200);  // start serial for output
  Serial.println("");
  Serial.println("--------------------------------------");

  // Unique Device ID
  Serial.print("# Device ID  : ");
  Serial.print(DEVICE_ID_HIGH, HEX);
  Serial.println(DEVICE_ID_LOW, HEX);

  // MCU Variant;
  Serial.printf("# MCU Variant: nRF%X 0x%08X\n", NRF_FICR->INFO.PART, NRF_FICR->INFO.VARIANT);
  Serial.printf("# Memory     : Flash = %d KB, RAM = %d KB\n", NRF_FICR->INFO.FLASH, NRF_FICR->INFO.RAM);
  Serial.println("");

  Serial.println("# PineTime 40 Starting.");
  Serial.println("");
  while (!Serial) delay(100);

  Serial.println("");
  while (!Serial) delay(100);
  Serial.println(">BL INIT");
  bl_init();
  while (!Serial) delay(100);
  Serial.println(">BL END");
  Serial.println("");

  /*
  Adafruit_LittleFS_Namespace::File file(ExternalFS);
  Serial.println("External FS read Boot file ");
  file.open(FILENAME, FILE_O_READ);
  //while (1) delay(1);
  // file existed 
  if (file) {
    Serial.println(FILENAME " file exists");

    uint32_t readlen;
    char buffer[64] = { 0 };
    readlen = file.read(buffer, sizeof(buffer));

    buffer[readlen] = 0;
    Serial.println(buffer);
    file.close();
  }
  else {
    Serial.print("Open " FILENAME " file to write ... ");

    if (file.open(FILENAME, FILE_O_WRITE)) {
      Serial.println("OK");
      file.write(CONTENTS, strlen(CONTENTS));
      file.close();
    } else {
      Serial.println("Failed!");
    }
  }

  Serial.println("External FS read Boot file Done");
  Serial.println("");
*/

  Serial.println("");

  Serial.println("> Backlight init");
  backlight.init();
  backlight.set_value_fast(16);

  Serial.println("> LVGL init");
  lv_init();

  lvgl_drv_init();

  init_watch();

  Serial.println("> UI init");
  ui_init();

  Serial.println("> Setup done...");
  run();

  //while (1) delay(1);

  Serial.println("");
  Serial.println("> File system, Internal and External ");
  Serial.println("");
  // Initialize Internal File System
  InternalFS.begin();

  Serial.println("> Internal FS List Files");
  // Print whole directory tree of root whose level is 0
  printTreeDirInt("/", 0);
  Serial.println("");

  if (!ExternalFS.begin()) {
    Serial.println(">> Error: filesystem not found, mount error.");
    while (1) delay(1);
  }

  //ExternalFS.mkdir("/config");
  Serial.println("");
  Serial.println("> External FS List Files");
  // Print whole directory tree of root whose level is 0
  printTreeDir("/", 0);
  Serial.println("");
  Serial.println("> Smartwatch running...");
  Serial.println("");
}

// ---------------------------------------------------------------------------------------------------------------------------------

void loop() {

  lv_timer_handler(); /* let the GUI do its work */
  old_sleep = lv_disp_get_inactive_time(lv_disp_get_default());

  if (old_sleep > 30000) {
    backlight.dim();
    /*if (old_sleep > 20000) {
      goto_home();
    }*/
  } else {
    backlight.restore_dim();
  }
  watchdog_feed();
  //lv_tick_inc(20);
  delay(5);
}