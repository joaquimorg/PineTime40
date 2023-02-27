#ifndef PINETIME_H
#define PINETIME_H

#include <stdlib.h>
#include <pinetime40.h>
#include <bluefruit.h>
#include "notification.h"
#include "SparkFun_BMA400_Arduino_Library.h"

#define SCREEN_BUFFER_SIZE 100
#define SW_SLEEP_MS 20000

#define VBAT_MV_PER_LSB (0.73242188F)  // 3.0V ADC range and 12-bit ADC resolution = 3000mV/4096

#define VBAT_DIVIDER (0.50F)       // 1M + 1M voltage divider on VBAT = (1M / (1M + 1M))
#define VBAT_DIVIDER_COMP (2.05F)  // Compensation factor for the VBAT divider

#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)


/*
  System message
*/
#define MSG_POWER_BUTTON  0x01
#define MSG_CHARGING      0x02
#define MSG_NOTIFICATION  0x03


struct Weather {
  int8_t currentTemp;
  uint8_t currentHumidity;
  int8_t todayMaxTemp;
  int8_t todayMinTemp;
  char *location;
  char *currentCondition;
  bool newData;
  bool hasData;
};

class PineTime {

public:

  enum class States {
    Idle,
    Running
  };

  RTCTime rtctime;
  Backlight backlight;

  PineTime(void);
  void begin(void);
  void loop(void);

  static inline void powerButtonHandler(void);
  static inline void chargingStatusHandler(void);
  static inline void touchpadRead(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
  static inline void dispFlush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
  static inline void callUpdateScreenCB(lv_timer_t *timer);
  static inline void readStatusCB(TimerHandle_t xTimer);
  static inline void disconnectCallback(uint16_t conn_handle, uint8_t reason);
  static inline void connectCallback(uint16_t conn_handle);
  static inline void bleuartRXcallback(uint16_t conn_hdl);

  static inline void powerButtonCB(lv_msg_t *m);
  static inline void chargingStatusCB(lv_msg_t *m);
  static inline void notificationCB(lv_msg_t *m);

  static inline void bma400InterruptHandler(void);

  float readVBAT(void);
  uint8_t mvToPercent(float mvolts);
  void readBatteryStatus(void);
  void showDebugBattStatus(void);
  void readStatus(void);

  void updateScreen(void (*)(void));
  void updateNotification(void (*)(void));

  bool battIsCharging(void) {
    return isCharging;
  };
  float battVoltage(void) {
    return vbat_mv;
  };
  uint8_t battPercent(void) {
    return vbat_per;
  };

  void rxDecode(void);

  void bleSetStatus(bool connected) {
    bleConnected = connected;
  };

  bool bleIsConnected(void) {
    return bleConnected;
  }

  void wakeUp(void);
  void goToSleep(void);

  Weather getWeather(void) { return weather; };
  void setNewWeatherData(bool newdata) { weather.newData = newdata; };

  Notification getNotification(void) { return notification; };


  uint32_t getStepCount(void) { return stepCount; };

private:

  Weather weather;
  Notification notification;
  BMA400 accelerometer;

  TimerHandle_t buttonTimer;
  States state = States::Running;

  static PineTime *active_object;
  uint32_t old_sleep = 0;
  unsigned long lastPress;
  float vbat_mv = 0.0;
  uint8_t vbat_per = 0;
  bool isCharging = false;

  uint16_t countrx = 0;
  uint8_t inputEnd = 1;

  int16_t msgSize = 0;
  uint8_t msgType = 0;

  bool bleConnected = false;

  uint32_t stepCount = 0;
  uint8_t activityType = 0;

  lv_timer_t *timerUpdateScreen;

  static const uint16_t screenWidth = 240;
  static const uint16_t screenHeight = 240;

  lv_disp_draw_buf_t draw_buf;
  lv_color_t buf_1[screenWidth * SCREEN_BUFFER_SIZE];

  Touch touch;

  // BLE Service
  //BLEDfu  bledfu;  // OTA DFU service
  BLEDis bledis;    // device information
  BLEUart bleuart;  // uart over ble
  //BLEBas blebas;    // battery

  SoftwareTimer timerStatus;

  void (*_updateScreen)(void);
  void (*_updateNotification)(void);

  void lvglInitDrivers(void);
  void statusWorkTimer(void);
  void powerButtonInit(void);
  void chargingStatusInit(void);

  void bluetoothInit(void);
  void bluetoothStartAdvertising(void);

  void initWorkTimers(void);

  uint32_t getUartInt(void);
  uint8_t getUartByte(void);

  void bleuartSendData(const uint8_t *content, size_t len);

  void bleSendVersion(void);
  void bleSendBattery(void);
  void bleSendSteps(void);
  void bleSendHR(void);

  void bleNotification(void);
  void bleWeather(void);

  void bleDecodeMessage(uint8_t msgType, int16_t msgSize);

  void systemMessages(void);

  void stepsConfig(void);
};

extern PineTime pinetime;

#endif  //PINETIME_H