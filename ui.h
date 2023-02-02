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

void ui_event_Clock(lv_event_t * e);
extern lv_obj_t * ui_Clock;
extern lv_obj_t * ui_Clock_Panel4;
extern lv_obj_t * ui_Clock_Hour;
extern lv_obj_t * ui_Clock_Minute;
extern lv_obj_t * ui_Clock_wd1;
extern lv_obj_t * ui_Clock_wd2;
extern lv_obj_t * ui_Clock_wd3;
extern lv_obj_t * ui_Clock_wd4;
extern lv_obj_t * ui_Clock_wd5;
extern lv_obj_t * ui_Clock_wd6;
extern lv_obj_t * ui_Clock_wd7;
extern lv_obj_t * ui_Clock_dot;
void ui_event_Config(lv_event_t * e);
extern lv_obj_t * ui_Config;
extern lv_obj_t * ui_Config_Panel2;
void ui_event_Config_Button1(lv_event_t * e);
extern lv_obj_t * ui_Config_Button1;
extern lv_obj_t * ui_Config_Label5;
void ui_event_Config_Button2(lv_event_t * e);
extern lv_obj_t * ui_Config_Button2;
extern lv_obj_t * ui_Config_Label1;
void ui_event_Config_Button3(lv_event_t * e);
extern lv_obj_t * ui_Config_Button3;
extern lv_obj_t * ui_Config_Label2;
void ui_event_Config_Button4(lv_event_t * e);
extern lv_obj_t * ui_Config_Button4;
extern lv_obj_t * ui_Config_Label3;
void ui_event_Config_Button5(lv_event_t * e);
extern lv_obj_t * ui_Config_Button5;
extern lv_obj_t * ui_Config_Label7;
void ui_event_Config_Button6(lv_event_t * e);
extern lv_obj_t * ui_Config_Button6;
extern lv_obj_t * ui_Config_Label8;
extern lv_obj_t * ui_Config_Label6;
extern lv_obj_t * ui_Config_Time;
void ui_event_About(lv_event_t * e);
extern lv_obj_t * ui_About;
extern lv_obj_t * ui_About_Panel1;
extern lv_obj_t * ui_About_Label1;
extern lv_obj_t * ui_Config_Label4;
extern lv_obj_t * ui_About_Panel2;
extern lv_obj_t * ui_About_info;
void ui_event_Backlight(lv_event_t * e);
extern lv_obj_t * ui_Backlight;
extern lv_obj_t * ui_Backlight_Panel3;
extern lv_obj_t * ui_Backlight_Label2;
extern lv_obj_t * ui_Backlight_Icon;
void ui_event_Backlight_Select(lv_event_t * e);
extern lv_obj_t * ui_Backlight_Select;
extern lv_obj_t * ui_Backlight_Value;
void ui_event_SetTime(lv_event_t * e);
extern lv_obj_t * ui_SetTime;
extern lv_obj_t * ui_SetTime_Panel;
extern lv_obj_t * ui_SetTime_Label3;
extern lv_obj_t * ui_SetTime_Label8;
extern lv_obj_t * ui_RollerTime;
extern lv_obj_t * ui_Backlight_Value1;
extern lv_obj_t * ui_RollerMinute;
void ui_event_SetDate(lv_event_t * e);
extern lv_obj_t * ui_SetDate;
extern lv_obj_t * ui_SetTime_Panel1;
extern lv_obj_t * ui_SetDate_Label4;
extern lv_obj_t * ui_SetTime_Label1;
extern lv_obj_t * ui_Roller1;
extern lv_obj_t * ui_Roller2;
extern lv_obj_t * ui_Roller3;
void ui_event_Messages(lv_event_t * e);
extern lv_obj_t * ui_Messages;
extern lv_obj_t * ui_Messages_Panel;
extern lv_obj_t * ui_Messages_Label5;
extern lv_obj_t * ui_SetTime_Label2;
extern lv_obj_t * ui_Messages_Label6;
void ui_event_Steps(lv_event_t * e);
extern lv_obj_t * ui_Steps;
extern lv_obj_t * ui_Steps_Panel1;
extern lv_obj_t * ui_StepsLabel1;
extern lv_obj_t * ui_StepsIcon;
extern lv_obj_t * ui_Steps_Value1;
extern lv_obj_t * ui_StepsLabel2;
void ui_event_Heart(lv_event_t * e);
extern lv_obj_t * ui_Heart;
extern lv_obj_t * ui_Steps_Panel2;
extern lv_obj_t * ui_HeartLabel2;
extern lv_obj_t * ui_HeartIcon1;
extern lv_obj_t * ui_HRValue2;
extern lv_obj_t * ui_HRLabel3;
extern lv_obj_t * ui_Chart2;
void ui_event_Status(lv_event_t * e);
extern lv_obj_t * ui_Status;
extern lv_obj_t * ui_Status_Panel;
extern lv_obj_t * ui_StatusLabel1;
extern lv_obj_t * ui_BattStatus;
extern lv_obj_t * ui_ChargingStatus;

void set_bl_value(lv_event_t * e);
void set_backlight(lv_event_t * e);
void setStatus(lv_event_t * e);



LV_FONT_DECLARE(ui_font_BigNumbers);
LV_FONT_DECLARE(ui_font_Icons32);
LV_FONT_DECLARE(ui_font_Numbers42);
LV_FONT_DECLARE(ui_font_OpenSans22);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
