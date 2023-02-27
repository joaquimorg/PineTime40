// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.3
// PROJECT: Pinetime

#ifndef _PINETIME_UI_H
#define _PINETIME_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


extern lv_obj_t * ui_Steps_Panel1;
extern lv_obj_t * ui_ImageW1;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Steps_Value1;
extern lv_obj_t * ui_StepsToday;
extern lv_obj_t * ui_PanelGoal;
extern lv_obj_t * ui_StepsGoalLbl;
extern lv_obj_t * ui_StepsGoal;

extern lv_obj_t * ui_Heart_Panel;
extern lv_obj_t * ui_HeartIcon;
extern lv_obj_t * ui_HeartValue;
extern lv_obj_t * ui_HRValue;
extern lv_obj_t * ui_HRbpmLabel;
extern lv_obj_t * ui_ChartHeart;

extern lv_obj_t * ui_Messages_Panel;
extern lv_obj_t * ui_MsgNoNotif;
extern lv_obj_t * ui_Messages_Label5;
extern lv_obj_t * ui_Notification_Icon;
extern lv_obj_t * ui_Messages_Label6;
extern lv_obj_t * ui_PanelListNotf;
extern lv_obj_t * ui_NotifHeader;
extern lv_obj_t * ui_NotifHeadTitle;
extern lv_obj_t * ui_NotifHeadTime;
extern lv_obj_t * ui_PanelNotif;

extern lv_obj_t * ui_Clock02_Panel3;
extern lv_obj_t * ui_Clock02_Minute3;
extern lv_obj_t * ui_Clock02_Hour3;
extern lv_obj_t * ui_Clock02Seconds1;
extern lv_obj_t * ui_Clock02DatePanel3;
extern lv_obj_t * ui_Clock02_Date8;
extern lv_obj_t * ui_Clock02_Date10;
extern lv_obj_t * ui_Clock02BlaPanel3;
extern lv_obj_t * ui_Clock02Ble3;
extern lv_obj_t * ui_Clock02PwrPanel3;
extern lv_obj_t * ui_imgPower1;
extern lv_obj_t * ui_Clock02_Power3;
extern lv_obj_t * ui_Clock02StepsPanel2;
extern lv_obj_t * ui_imgWalk1;
extern lv_obj_t * ui_Clock02_Date12;
extern lv_obj_t * ui_Clock02HRPanel2;
extern lv_obj_t * ui_imgHeart1;
extern lv_obj_t * ui_Clock02_Date13;
extern lv_obj_t * ui_Clock02MsgPanel1;
extern lv_obj_t * ui_Clock02Msg1;

LV_IMG_DECLARE(ui_img_bluetooth_png);    // assets\bluetooth.png
LV_IMG_DECLARE(ui_img_power_png);    // assets\power.png
LV_IMG_DECLARE(ui_img_walk_png);    // assets\walk.png
LV_IMG_DECLARE(ui_img_heart_png);    // assets\heart.png
LV_IMG_DECLARE(ui_img_heart_pulse_png);    // assets\heart_pulse.png
LV_IMG_DECLARE(ui_img_message_png);    // assets\message.png
LV_IMG_DECLARE(ui_img_walk1_png);    // assets\walk1.png
LV_IMG_DECLARE(ui_img_walk2_png);    // assets\walk2.png
LV_IMG_DECLARE(ui_img_walk3_png);    // assets\walk3.png
LV_IMG_DECLARE(ui_img_walk4_png);    // assets\walk4.png


LV_FONT_DECLARE(ui_font_BigNumbers);
LV_FONT_DECLARE(ui_font_Icons32);
LV_FONT_DECLARE(ui_font_Numbers42);
LV_FONT_DECLARE(ui_font_OpenSans22);
LV_FONT_DECLARE(ui_font_Weather);
LV_FONT_DECLARE(ui_font_Numbers64);
LV_FONT_DECLARE(ui_font_OpenSans22Bold);

void ui_Steps_screen_init(lv_obj_t *tile);
void ui_Clock02_screen_init(lv_obj_t *tile);
void ui_Messages_screen_init(lv_obj_t *tile);
void ui_Heart_screen_init(lv_obj_t *tile);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
