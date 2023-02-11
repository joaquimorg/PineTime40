#include "PineTime.h"
#include <stdlib.h>

#include "ui.h"
#include "ui_events.h"

typedef volatile uint32_t REG32;
#define pREG32 (REG32 *)

#define DEVICE_ID_HIGH (*(pREG32(0x10000060)))
#define DEVICE_ID_LOW (*(pREG32(0x10000064)))

// ---------------------------------------------------------------------------------------------------------------------------------

void get_batt_icon() {
  if (pinetime.battIsCharging()) {
    lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
    //lv_label_set_text_fmt(ui_BattIcon5, "");
    lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0xFFFF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  } else {
    if (pinetime.battPercent() < 10) {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    } else if (pinetime.battPercent() < 30) {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0xFFFF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    } else if (pinetime.battPercent() < 50) {
      lv_label_set_text_fmt(ui_Config_Batt_Icon, "");
      //lv_label_set_text_fmt(ui_BattIcon5, "");
      lv_obj_set_style_arc_color(ui_BattLvl, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    } else if (pinetime.battPercent() < 85) {
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


//void ble_send_battery(void);

static void batt_status() {
  //ble_send_battery();
  lv_label_set_text_fmt(ui_ConfigBatt, "%d%%", pinetime.battPercent());
  get_batt_icon();
  lv_label_set_text_fmt(ui_BattStatus, "%.2f V", pinetime.battVoltage() / 1000);
  lv_label_set_text_fmt(ui_BattPerc, "%d%%", pinetime.battPercent());
  lv_arc_set_value(ui_BattLvl, pinetime.battPercent());
}

// ---------------------------------------------------------------------------------------------------------------------------------


uint8_t old_min = 99;
uint8_t old_min_c = 99;
uint8_t old_hour = 99;
uint8_t old_day = 99;


void update_day() {
  lv_obj_set_style_text_color(ui_Clock_wd1, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd2, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd3, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd4, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd5, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd6, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_Clock_wd7, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);

  switch (pinetime.rtctime.week()) {
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

  pinetime.rtctime.get_time();

  if (curr_screen == ui_Clock) {
    if (old_min != pinetime.rtctime.minutes()) {
      lv_label_set_text_fmt(ui_Clock_Minute, "%02i", pinetime.rtctime.minutes());
      old_min = pinetime.rtctime.minutes();
    }
    if (old_hour != pinetime.rtctime.hours()) {
      lv_label_set_text_fmt(ui_Clock_Hour, "%02i", pinetime.rtctime.hours());
      old_hour = pinetime.rtctime.hours();
    }
    if (old_day != pinetime.rtctime.week()) {
      update_day();
      old_day = pinetime.rtctime.week();
    }
  } else if (curr_screen == ui_Config) {
    if (old_min_c != pinetime.rtctime.minutes()) {
      lv_label_set_text_fmt(ui_Config_Time, "%02i:%02i", pinetime.rtctime.hours(), pinetime.rtctime.minutes());
      old_min_c = pinetime.rtctime.minutes();
    }
  } else {
    old_min = 99;
    old_min_c = 99;
    old_hour = 99;
    old_day = 99;
  }

  batt_status();
}

// ---------------------------------------------------------------------------------------------------------------------------------

void _set_backlight(lv_event_t *e) {
  lv_obj_t *target = lv_event_get_target(e);
  pinetime.backlight.set_value_fast((int)lv_arc_get_value(target));
  lv_label_set_text_fmt(ui_Backlight_Value, "%d%%", pinetime.backlight.get_value() * 100 / 128);
}


void _set_bl_value(lv_event_t *e) {
  lv_arc_set_value(ui_Backlight_Select, pinetime.backlight.get_value());
  lv_label_set_text_fmt(ui_Backlight_Value, "%d%%", pinetime.backlight.get_value() * 100 / 128);
}


void _quick_setings(lv_event_t *e) {
  //lv_label_set_text_fmt(ui_ConfigBatt, "%d%%", pinetime.battPercent());
  //get_batt_icon();
}


void _charging_load(lv_event_t *e) {
  /*read_batt_status();

  get_batt_icon();

  lv_label_set_text_fmt(ui_BattStatus, "%.2f V", vbat_mv / 1000);

  lv_label_set_text_fmt(ui_BattPerc, "%d%%", pinetime.battPercent());
  lv_arc_set_value(ui_BattLvl, pinetime.battPercent());*/

}

// ---------------------------------------------------------------------------------------------------------------------------------

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

  // Init PineTime Hardware
  pinetime.begin();
  pinetime.updateScreen(update_clock);
}

// ---------------------------------------------------------------------------------------------------------------------------------

void loop() {
  pinetime.loop();
  delay(5);
}