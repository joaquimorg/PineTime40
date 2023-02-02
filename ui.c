// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.3
// PROJECT: Pinetime

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void ui_event_Clock(lv_event_t * e);
lv_obj_t * ui_Clock;
lv_obj_t * ui_Clock_Panel4;
lv_obj_t * ui_Clock_Hour;
lv_obj_t * ui_Clock_Minute;
lv_obj_t * ui_Clock_wd1;
lv_obj_t * ui_Clock_wd2;
lv_obj_t * ui_Clock_wd3;
lv_obj_t * ui_Clock_wd4;
lv_obj_t * ui_Clock_wd5;
lv_obj_t * ui_Clock_wd6;
lv_obj_t * ui_Clock_wd7;
lv_obj_t * ui_Clock_dot;
void ui_event_Config(lv_event_t * e);
lv_obj_t * ui_Config;
lv_obj_t * ui_Config_Panel2;
void ui_event_Config_Button1(lv_event_t * e);
lv_obj_t * ui_Config_Button1;
lv_obj_t * ui_Config_Label5;
void ui_event_Config_Button2(lv_event_t * e);
lv_obj_t * ui_Config_Button2;
lv_obj_t * ui_Config_Label1;
void ui_event_Config_Button3(lv_event_t * e);
lv_obj_t * ui_Config_Button3;
lv_obj_t * ui_Config_Label2;
void ui_event_Config_Button4(lv_event_t * e);
lv_obj_t * ui_Config_Button4;
lv_obj_t * ui_Config_Label3;
void ui_event_Config_Button5(lv_event_t * e);
lv_obj_t * ui_Config_Button5;
lv_obj_t * ui_Config_Label7;
void ui_event_Config_Button6(lv_event_t * e);
lv_obj_t * ui_Config_Button6;
lv_obj_t * ui_Config_Label8;
lv_obj_t * ui_Config_Label6;
lv_obj_t * ui_Config_Time;
void ui_event_About(lv_event_t * e);
lv_obj_t * ui_About;
lv_obj_t * ui_About_Panel1;
lv_obj_t * ui_About_Label1;
lv_obj_t * ui_Config_Label4;
lv_obj_t * ui_About_Panel2;
lv_obj_t * ui_About_info;
void ui_event_Backlight(lv_event_t * e);
lv_obj_t * ui_Backlight;
lv_obj_t * ui_Backlight_Panel3;
lv_obj_t * ui_Backlight_Label2;
lv_obj_t * ui_Backlight_Icon;
void ui_event_Backlight_Select(lv_event_t * e);
lv_obj_t * ui_Backlight_Select;
lv_obj_t * ui_Backlight_Value;
void ui_event_SetTime(lv_event_t * e);
lv_obj_t * ui_SetTime;
lv_obj_t * ui_SetTime_Panel;
lv_obj_t * ui_SetTime_Label3;
lv_obj_t * ui_SetTime_Label8;
lv_obj_t * ui_RollerTime;
lv_obj_t * ui_Backlight_Value1;
lv_obj_t * ui_RollerMinute;
void ui_event_SetDate(lv_event_t * e);
lv_obj_t * ui_SetDate;
lv_obj_t * ui_SetTime_Panel1;
lv_obj_t * ui_SetDate_Label4;
lv_obj_t * ui_SetTime_Label1;
lv_obj_t * ui_Roller1;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_Roller3;
void ui_event_Messages(lv_event_t * e);
lv_obj_t * ui_Messages;
lv_obj_t * ui_Messages_Panel;
lv_obj_t * ui_Messages_Label5;
lv_obj_t * ui_SetTime_Label2;
lv_obj_t * ui_Messages_Label6;
void ui_event_Steps(lv_event_t * e);
lv_obj_t * ui_Steps;
lv_obj_t * ui_Steps_Panel1;
lv_obj_t * ui_StepsLabel1;
lv_obj_t * ui_StepsIcon;
lv_obj_t * ui_Steps_Value1;
lv_obj_t * ui_StepsLabel2;
void ui_event_Heart(lv_event_t * e);
lv_obj_t * ui_Heart;
lv_obj_t * ui_Steps_Panel2;
lv_obj_t * ui_HeartLabel2;
lv_obj_t * ui_HeartIcon1;
lv_obj_t * ui_HRValue2;
lv_obj_t * ui_HRLabel3;
lv_obj_t * ui_Chart2;
void ui_event_Status(lv_event_t * e);
lv_obj_t * ui_Status;
lv_obj_t * ui_Status_Panel;
lv_obj_t * ui_StatusLabel1;
lv_obj_t * ui_BattStatus;
lv_obj_t * ui_ChargingStatus;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Clock(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
        _ui_screen_change(ui_Config, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        _ui_screen_change(ui_Messages, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Steps, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Heart, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0);
    }
}
void ui_event_Config(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        _ui_screen_change(ui_Clock, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 0);
    }
}
void ui_event_Config_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_SetTime, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_Config_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_SetDate, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_Config_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Backlight, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_Config_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_About, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_Config_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Status, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_Config_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_SetTime, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_About(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Config, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0);
    }
}
void ui_event_Backlight(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Config, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0);
    }
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        set_bl_value(e);
    }
}
void ui_event_Backlight_Select(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        set_backlight(e);
    }
}
void ui_event_SetTime(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Config, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0);
    }
}
void ui_event_SetDate(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Config, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 0);
    }
}
void ui_event_Messages(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
        _ui_screen_change(ui_Clock, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0);
    }
}
void ui_event_Steps(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Clock, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0);
    }
}
void ui_event_Heart(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Clock, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0);
    }
}
void ui_event_Status(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Config, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 0);
    }
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        setStatus(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Clock_screen_init(void)
{
    ui_Clock = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Clock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Clock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Clock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_Panel4 = lv_obj_create(ui_Clock);
    lv_obj_set_width(ui_Clock_Panel4, lv_pct(100));
    lv_obj_set_height(ui_Clock_Panel4, lv_pct(100));
    lv_obj_set_align(ui_Clock_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Clock_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Clock_Panel4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Clock_Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Clock_Panel4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Clock_Panel4, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Clock_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Clock_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Clock_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Clock_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_Hour = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_Hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Clock_Hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Clock_Hour, 40);
    lv_obj_set_y(ui_Clock_Hour, -55);
    lv_obj_set_align(ui_Clock_Hour, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_Hour, "00");
    lv_obj_set_style_text_font(ui_Clock_Hour, &ui_font_BigNumbers, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_Minute = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_Minute, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Clock_Minute, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Clock_Minute, 40);
    lv_obj_set_y(ui_Clock_Minute, 55);
    lv_obj_set_align(ui_Clock_Minute, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_Minute, "00");
    lv_obj_set_style_text_color(ui_Clock_Minute, lv_color_hex(0x323232), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_Minute, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_Minute, &ui_font_BigNumbers, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_wd1 = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_wd1, 55);
    lv_obj_set_height(ui_Clock_wd1, LV_SIZE_CONTENT);    /// 22
    lv_obj_set_x(ui_Clock_wd1, -66);
    lv_obj_set_y(ui_Clock_wd1, -83);
    lv_obj_set_align(ui_Clock_wd1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_wd1, "SUN");
    lv_obj_set_style_text_color(ui_Clock_wd1, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_wd1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_wd1, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_wd2 = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_wd2, 55);
    lv_obj_set_height(ui_Clock_wd2, LV_SIZE_CONTENT);    /// 18
    lv_obj_set_x(ui_Clock_wd2, -66);
    lv_obj_set_y(ui_Clock_wd2, -55);
    lv_obj_set_align(ui_Clock_wd2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_wd2, "MON");
    lv_obj_set_style_text_color(ui_Clock_wd2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_wd2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_wd2, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_wd3 = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_wd3, 55);
    lv_obj_set_height(ui_Clock_wd3, LV_SIZE_CONTENT);    /// 18
    lv_obj_set_x(ui_Clock_wd3, -66);
    lv_obj_set_y(ui_Clock_wd3, -27);
    lv_obj_set_align(ui_Clock_wd3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_wd3, "TUE");
    lv_obj_set_style_text_color(ui_Clock_wd3, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_wd3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_wd3, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_wd4 = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_wd4, 55);
    lv_obj_set_height(ui_Clock_wd4, LV_SIZE_CONTENT);    /// 18
    lv_obj_set_x(ui_Clock_wd4, -66);
    lv_obj_set_y(ui_Clock_wd4, 2);
    lv_obj_set_align(ui_Clock_wd4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_wd4, "WED");
    lv_obj_set_style_text_color(ui_Clock_wd4, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_wd4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_wd4, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_wd5 = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_wd5, 55);
    lv_obj_set_height(ui_Clock_wd5, LV_SIZE_CONTENT);    /// 18
    lv_obj_set_x(ui_Clock_wd5, -66);
    lv_obj_set_y(ui_Clock_wd5, 31);
    lv_obj_set_align(ui_Clock_wd5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_wd5, "THU");
    lv_obj_set_style_text_color(ui_Clock_wd5, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_wd5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_wd5, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_wd6 = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_wd6, 55);
    lv_obj_set_height(ui_Clock_wd6, LV_SIZE_CONTENT);    /// 18
    lv_obj_set_x(ui_Clock_wd6, -66);
    lv_obj_set_y(ui_Clock_wd6, 60);
    lv_obj_set_align(ui_Clock_wd6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_wd6, "FRI");
    lv_obj_set_style_text_color(ui_Clock_wd6, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_wd6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Clock_wd6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_wd6, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_wd7 = lv_label_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_wd7, 55);
    lv_obj_set_height(ui_Clock_wd7, LV_SIZE_CONTENT);    /// 18
    lv_obj_set_x(ui_Clock_wd7, -66);
    lv_obj_set_y(ui_Clock_wd7, 87);
    lv_obj_set_align(ui_Clock_wd7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Clock_wd7, "SAT");
    lv_obj_set_style_text_color(ui_Clock_wd7, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Clock_wd7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Clock_wd7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Clock_wd7, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Clock_dot = lv_obj_create(ui_Clock_Panel4);
    lv_obj_set_width(ui_Clock_dot, 8);
    lv_obj_set_height(ui_Clock_dot, 8);
    lv_obj_set_x(ui_Clock_dot, -105);
    lv_obj_set_y(ui_Clock_dot, -55);
    lv_obj_set_align(ui_Clock_dot, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Clock_dot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Clock_dot, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Clock_dot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Clock_dot, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Clock, ui_event_Clock, LV_EVENT_ALL, NULL);

}
void ui_Config_screen_init(void)
{
    ui_Config = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Config, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Config, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Panel2 = lv_obj_create(ui_Config);
    lv_obj_set_width(ui_Config_Panel2, 240);
    lv_obj_set_height(ui_Config_Panel2, 240);
    lv_obj_set_align(ui_Config_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Config_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Config_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Config_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Button1 = lv_btn_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Button1, 70);
    lv_obj_set_height(ui_Config_Button1, 70);
    lv_obj_set_x(ui_Config_Button1, -74);
    lv_obj_set_y(ui_Config_Button1, -71);
    lv_obj_set_align(ui_Config_Button1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Config_Button1,
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_Config_Button1, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button1, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button1, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Config_Button1, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Config_Label5 = lv_label_create(ui_Config_Button1);
    lv_obj_set_width(ui_Config_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Config_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Config_Label5, "");
    lv_obj_set_style_text_font(ui_Config_Label5, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Button2 = lv_btn_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Button2, 70);
    lv_obj_set_height(ui_Config_Button2, 70);
    lv_obj_set_x(ui_Config_Button2, 0);
    lv_obj_set_y(ui_Config_Button2, -72);
    lv_obj_set_align(ui_Config_Button2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Config_Button2,
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_Config_Button2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button2, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button2, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Config_Button2, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Config_Label1 = lv_label_create(ui_Config_Button2);
    lv_obj_set_width(ui_Config_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Config_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Config_Label1, "");
    lv_obj_set_style_text_font(ui_Config_Label1, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Button3 = lv_btn_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Button3, 70);
    lv_obj_set_height(ui_Config_Button3, 70);
    lv_obj_set_x(ui_Config_Button3, 74);
    lv_obj_set_y(ui_Config_Button3, -73);
    lv_obj_set_align(ui_Config_Button3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Config_Button3,
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_Config_Button3, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button3, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button3, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Config_Button3, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Config_Label2 = lv_label_create(ui_Config_Button3);
    lv_obj_set_width(ui_Config_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Config_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Config_Label2, "");
    lv_obj_set_style_text_font(ui_Config_Label2, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Button4 = lv_btn_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Button4, 70);
    lv_obj_set_height(ui_Config_Button4, 70);
    lv_obj_set_x(ui_Config_Button4, -74);
    lv_obj_set_y(ui_Config_Button4, 18);
    lv_obj_set_align(ui_Config_Button4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Config_Button4,
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_Config_Button4, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button4, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button4, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Config_Button4, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Config_Label3 = lv_label_create(ui_Config_Button4);
    lv_obj_set_width(ui_Config_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Config_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Config_Label3, "");
    lv_obj_set_style_text_font(ui_Config_Label3, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Button5 = lv_btn_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Button5, 70);
    lv_obj_set_height(ui_Config_Button5, 70);
    lv_obj_set_x(ui_Config_Button5, 0);
    lv_obj_set_y(ui_Config_Button5, 18);
    lv_obj_set_align(ui_Config_Button5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Config_Button5,
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_Config_Button5, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button5, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button5, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Config_Button5, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Config_Label7 = lv_label_create(ui_Config_Button5);
    lv_obj_set_width(ui_Config_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Config_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Config_Label7, "");
    lv_obj_set_style_text_font(ui_Config_Label7, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Button6 = lv_btn_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Button6, 70);
    lv_obj_set_height(ui_Config_Button6, 70);
    lv_obj_set_x(ui_Config_Button6, 74);
    lv_obj_set_y(ui_Config_Button6, 18);
    lv_obj_set_align(ui_Config_Button6, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Config_Button6,
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_Config_Button6, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button6, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Config_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Config_Button6, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Config_Button6, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Config_Label8 = lv_label_create(ui_Config_Button6);
    lv_obj_set_width(ui_Config_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Config_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Config_Label8, "");
    lv_obj_set_style_text_font(ui_Config_Label8, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Label6 = lv_label_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Config_Label6, -10);
    lv_obj_set_y(ui_Config_Label6, 0);
    lv_obj_set_align(ui_Config_Label6, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(ui_Config_Label6, "");
    lv_obj_set_style_text_color(ui_Config_Label6, lv_color_hex(0x017515), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Config_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Config_Label6, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Time = lv_label_create(ui_Config_Panel2);
    lv_obj_set_width(ui_Config_Time, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Config_Time, 10);
    lv_obj_set_y(ui_Config_Time, -10);
    lv_obj_set_align(ui_Config_Time, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_Config_Time, "00:00");
    lv_obj_set_style_text_font(ui_Config_Time, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Config_Button1, ui_event_Config_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Config_Button2, ui_event_Config_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Config_Button3, ui_event_Config_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Config_Button4, ui_event_Config_Button4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Config_Button5, ui_event_Config_Button5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Config_Button6, ui_event_Config_Button6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Config, ui_event_Config, LV_EVENT_ALL, NULL);

}
void ui_About_screen_init(void)
{
    ui_About = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_About, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_About, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_About, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_About_Panel1 = lv_obj_create(ui_About);
    lv_obj_set_width(ui_About_Panel1, lv_pct(100));
    lv_obj_set_height(ui_About_Panel1, lv_pct(100));
    lv_obj_set_align(ui_About_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_About_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_About_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_About_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_About_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_About_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_About_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_About_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_About_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_About_Label1 = lv_label_create(ui_About_Panel1);
    lv_obj_set_width(ui_About_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_About_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_About_Label1, 5);
    lv_obj_set_y(ui_About_Label1, 13);
    lv_label_set_text(ui_About_Label1, "About");
    lv_obj_set_style_text_color(ui_About_Label1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_About_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_About_Label1, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Config_Label4 = lv_label_create(ui_About_Panel1);
    lv_obj_set_width(ui_Config_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Config_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Config_Label4, -8);
    lv_obj_set_y(ui_Config_Label4, 8);
    lv_obj_set_align(ui_Config_Label4, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Config_Label4, "");
    lv_obj_set_style_text_color(ui_Config_Label4, lv_color_hex(0x33D9B2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Config_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Config_Label4, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_About_Panel2 = lv_obj_create(ui_About_Panel1);
    lv_obj_set_width(ui_About_Panel2, lv_pct(95));
    lv_obj_set_height(ui_About_Panel2, lv_pct(76));
    lv_obj_set_x(ui_About_Panel2, 0);
    lv_obj_set_y(ui_About_Panel2, 23);
    lv_obj_set_align(ui_About_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_About_Panel2, LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLL_CHAIN);      /// Flags
    lv_obj_set_style_radius(ui_About_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_About_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_About_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_About_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_About_Panel2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_About_Panel2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_About_Panel2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_About_Panel2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_About_info = lv_label_create(ui_About_Panel2);
    lv_obj_set_width(ui_About_info, lv_pct(100));
    lv_obj_set_height(ui_About_info, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_align(ui_About_info, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_About_info,
                      "Name\n#555555 Pinetime nRF52840#\n\nModel\n#555555 Pinetime Arduino#\n\nVersion\n#555555 2023.001#\n\n#ff0000 (c) 2023 joaquim.org#");
    lv_label_set_recolor(ui_About_info, "true");
    lv_obj_clear_flag(ui_About_info, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_About_info, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_align(ui_About_info, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_About_info, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_About, ui_event_About, LV_EVENT_ALL, NULL);

}
void ui_Backlight_screen_init(void)
{
    ui_Backlight = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Backlight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Backlight, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Backlight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Backlight_Panel3 = lv_obj_create(ui_Backlight);
    lv_obj_set_width(ui_Backlight_Panel3, lv_pct(100));
    lv_obj_set_height(ui_Backlight_Panel3, lv_pct(100));
    lv_obj_set_align(ui_Backlight_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Backlight_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Backlight_Panel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Backlight_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Backlight_Panel3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Backlight_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Backlight_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Backlight_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Backlight_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Backlight_Label2 = lv_label_create(ui_Backlight_Panel3);
    lv_obj_set_width(ui_Backlight_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Backlight_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Backlight_Label2, 5);
    lv_obj_set_y(ui_Backlight_Label2, 13);
    lv_label_set_text(ui_Backlight_Label2, "Backlight");
    lv_obj_set_style_text_color(ui_Backlight_Label2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Backlight_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Backlight_Label2, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Backlight_Icon = lv_label_create(ui_Backlight_Panel3);
    lv_obj_set_width(ui_Backlight_Icon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Backlight_Icon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Backlight_Icon, -8);
    lv_obj_set_y(ui_Backlight_Icon, 8);
    lv_obj_set_align(ui_Backlight_Icon, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Backlight_Icon, "");
    lv_obj_set_style_text_color(ui_Backlight_Icon, lv_color_hex(0x33D9B2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Backlight_Icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Backlight_Icon, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Backlight_Select = lv_arc_create(ui_Backlight_Panel3);
    lv_obj_set_width(ui_Backlight_Select, 180);
    lv_obj_set_height(ui_Backlight_Select, 180);
    lv_obj_set_x(ui_Backlight_Select, 0);
    lv_obj_set_y(ui_Backlight_Select, 25);
    lv_obj_set_align(ui_Backlight_Select, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Backlight_Select,
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_arc_set_range(ui_Backlight_Select, 1, 128);
    lv_arc_set_value(ui_Backlight_Select, 100);
    lv_obj_set_style_arc_color(ui_Backlight_Select, lv_color_hex(0x0B0B0B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Backlight_Select, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Backlight_Select, lv_color_hex(0xFFD800), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Backlight_Select, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Backlight_Select, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Backlight_Select, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Backlight_Select, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Backlight_Select, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Backlight_Select, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Backlight_Select, 10, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Backlight_Value = lv_label_create(ui_Backlight_Panel3);
    lv_obj_set_width(ui_Backlight_Value, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Backlight_Value, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Backlight_Value, 0);
    lv_obj_set_y(ui_Backlight_Value, 25);
    lv_obj_set_align(ui_Backlight_Value, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Backlight_Value, "100%");
    lv_obj_set_style_text_font(ui_Backlight_Value, &ui_font_Numbers42, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Backlight_Select, ui_event_Backlight_Select, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Backlight, ui_event_Backlight, LV_EVENT_ALL, NULL);

}
void ui_SetTime_screen_init(void)
{
    ui_SetTime = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SetTime, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SetTime, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SetTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SetTime_Panel = lv_obj_create(ui_SetTime);
    lv_obj_set_width(ui_SetTime_Panel, lv_pct(100));
    lv_obj_set_height(ui_SetTime_Panel, lv_pct(100));
    lv_obj_set_align(ui_SetTime_Panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SetTime_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SetTime_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SetTime_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SetTime_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SetTime_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SetTime_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SetTime_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SetTime_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SetTime_Label3 = lv_label_create(ui_SetTime_Panel);
    lv_obj_set_width(ui_SetTime_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SetTime_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SetTime_Label3, 5);
    lv_obj_set_y(ui_SetTime_Label3, 13);
    lv_label_set_text(ui_SetTime_Label3, "Set Time");
    lv_obj_set_style_text_color(ui_SetTime_Label3, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SetTime_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SetTime_Label3, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SetTime_Label8 = lv_label_create(ui_SetTime_Panel);
    lv_obj_set_width(ui_SetTime_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SetTime_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SetTime_Label8, -8);
    lv_obj_set_y(ui_SetTime_Label8, 8);
    lv_obj_set_align(ui_SetTime_Label8, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_SetTime_Label8, "");
    lv_obj_set_style_text_color(ui_SetTime_Label8, lv_color_hex(0x33D9B2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SetTime_Label8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SetTime_Label8, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RollerTime = lv_roller_create(ui_SetTime);
    lv_roller_set_options(ui_RollerTime,
                          "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_height(ui_RollerTime, 168);
    lv_obj_set_width(ui_RollerTime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_RollerTime, -46);
    lv_obj_set_y(ui_RollerTime, 24);
    lv_obj_set_align(ui_RollerTime, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_RollerTime, LV_OBJ_FLAG_GESTURE_BUBBLE);      /// Flags
    lv_obj_set_style_text_font(ui_RollerTime, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerTime, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_RollerTime, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_RollerTime, 10, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerTime, lv_color_hex(0x464646), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerTime, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Backlight_Value1 = lv_label_create(ui_SetTime);
    lv_obj_set_width(ui_Backlight_Value1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Backlight_Value1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Backlight_Value1, 0);
    lv_obj_set_y(ui_Backlight_Value1, 22);
    lv_obj_set_align(ui_Backlight_Value1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Backlight_Value1, ":");
    lv_obj_set_style_text_font(ui_Backlight_Value1, &ui_font_Numbers42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RollerMinute = lv_roller_create(ui_SetTime);
    lv_roller_set_options(ui_RollerMinute,
                          "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_height(ui_RollerMinute, 168);
    lv_obj_set_width(ui_RollerMinute, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_RollerMinute, 50);
    lv_obj_set_y(ui_RollerMinute, 24);
    lv_obj_set_align(ui_RollerMinute, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_RollerMinute, LV_OBJ_FLAG_GESTURE_BUBBLE);      /// Flags
    lv_obj_set_style_text_font(ui_RollerMinute, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerMinute, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerMinute, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_RollerMinute, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_RollerMinute, 10, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerMinute, lv_color_hex(0x464646), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerMinute, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SetTime, ui_event_SetTime, LV_EVENT_ALL, NULL);

}
void ui_SetDate_screen_init(void)
{
    ui_SetDate = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SetDate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SetDate, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SetDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SetTime_Panel1 = lv_obj_create(ui_SetDate);
    lv_obj_set_width(ui_SetTime_Panel1, lv_pct(100));
    lv_obj_set_height(ui_SetTime_Panel1, lv_pct(100));
    lv_obj_set_align(ui_SetTime_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SetTime_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SetTime_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SetTime_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SetTime_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SetTime_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SetTime_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SetTime_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SetTime_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SetDate_Label4 = lv_label_create(ui_SetTime_Panel1);
    lv_obj_set_width(ui_SetDate_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SetDate_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SetDate_Label4, 5);
    lv_obj_set_y(ui_SetDate_Label4, 6);
    lv_label_set_text(ui_SetDate_Label4, "Set Date");
    lv_obj_set_style_text_color(ui_SetDate_Label4, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SetDate_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SetDate_Label4, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SetTime_Label1 = lv_label_create(ui_SetTime_Panel1);
    lv_obj_set_width(ui_SetTime_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SetTime_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SetTime_Label1, -8);
    lv_obj_set_y(ui_SetTime_Label1, 8);
    lv_obj_set_align(ui_SetTime_Label1, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_SetTime_Label1, "");
    lv_obj_set_style_text_color(ui_SetTime_Label1, lv_color_hex(0x33D9B2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SetTime_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SetTime_Label1, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller1 = lv_roller_create(ui_SetDate);
    lv_roller_set_options(ui_Roller1, "Jan\nFeb\nMar\nApr\nMay\nJun\nJul\nAug\nSept\nOct\nNov\nDec",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_height(ui_Roller1, 180);
    lv_obj_set_width(ui_Roller1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_Roller1, 7);
    lv_obj_set_y(ui_Roller1, 21);
    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Roller1, LV_OBJ_FLAG_GESTURE_BUBBLE);      /// Flags
    lv_obj_set_style_text_font(ui_Roller1, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Roller1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Roller1, 10, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller1, lv_color_hex(0x464646), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Roller2 = lv_roller_create(ui_SetDate);
    lv_roller_set_options(ui_Roller2,
                          "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller2, 60);
    lv_obj_set_height(ui_Roller2, 180);
    lv_obj_set_x(ui_Roller2, 79);
    lv_obj_set_y(ui_Roller2, 21);
    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Roller2, LV_OBJ_FLAG_GESTURE_BUBBLE);      /// Flags
    lv_obj_set_style_text_font(ui_Roller2, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Roller2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Roller2, 10, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller2, lv_color_hex(0x464646), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller2, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Roller3 = lv_roller_create(ui_SetDate);
    lv_roller_set_options(ui_Roller3, "2023\n2024\n2025\n2026\n2027\n2028\n2029\n2030", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller3, 82);
    lv_obj_set_height(ui_Roller3, 180);
    lv_obj_set_x(ui_Roller3, -75);
    lv_obj_set_y(ui_Roller3, 21);
    lv_obj_set_align(ui_Roller3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Roller3, LV_OBJ_FLAG_GESTURE_BUBBLE);      /// Flags
    lv_obj_set_style_text_font(ui_Roller3, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Roller3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Roller3, 10, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller3, lv_color_hex(0x464646), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller3, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SetDate, ui_event_SetDate, LV_EVENT_ALL, NULL);

}
void ui_Messages_screen_init(void)
{
    ui_Messages = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Messages, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Messages, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Messages, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Messages_Panel = lv_obj_create(ui_Messages);
    lv_obj_set_width(ui_Messages_Panel, lv_pct(100));
    lv_obj_set_height(ui_Messages_Panel, lv_pct(100));
    lv_obj_set_align(ui_Messages_Panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Messages_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Messages_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Messages_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Messages_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Messages_Label5 = lv_label_create(ui_Messages_Panel);
    lv_obj_set_width(ui_Messages_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Messages_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Messages_Label5, 0);
    lv_obj_set_y(ui_Messages_Label5, 13);
    lv_obj_set_align(ui_Messages_Label5, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Messages_Label5, "Notifications");
    lv_obj_set_style_text_color(ui_Messages_Label5, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Messages_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Messages_Label5, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SetTime_Label2 = lv_label_create(ui_Messages_Panel);
    lv_obj_set_width(ui_SetTime_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SetTime_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SetTime_Label2, 0);
    lv_obj_set_y(ui_SetTime_Label2, -30);
    lv_obj_set_align(ui_SetTime_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SetTime_Label2, "");
    lv_obj_set_style_text_color(ui_SetTime_Label2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SetTime_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SetTime_Label2, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Messages_Label6 = lv_label_create(ui_Messages_Panel);
    lv_obj_set_width(ui_Messages_Label6, lv_pct(95));
    lv_obj_set_height(ui_Messages_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Messages_Label6, 0);
    lv_obj_set_y(ui_Messages_Label6, 47);
    lv_obj_set_align(ui_Messages_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Messages_Label6, "You don't have new notifications...");
    lv_obj_set_style_text_align(ui_Messages_Label6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Messages_Label6, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Messages, ui_event_Messages, LV_EVENT_ALL, NULL);

}
void ui_Steps_screen_init(void)
{
    ui_Steps = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Steps, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Steps, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Steps, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Steps_Panel1 = lv_obj_create(ui_Steps);
    lv_obj_set_width(ui_Steps_Panel1, lv_pct(100));
    lv_obj_set_height(ui_Steps_Panel1, lv_pct(100));
    lv_obj_set_align(ui_Steps_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Steps_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Steps_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Steps_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Steps_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StepsLabel1 = lv_label_create(ui_Steps_Panel1);
    lv_obj_set_width(ui_StepsLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_StepsLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_StepsLabel1, 5);
    lv_obj_set_y(ui_StepsLabel1, 13);
    lv_label_set_text(ui_StepsLabel1, "Steps");
    lv_obj_set_style_text_color(ui_StepsLabel1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StepsLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StepsLabel1, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StepsIcon = lv_label_create(ui_Steps_Panel1);
    lv_obj_set_width(ui_StepsIcon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_StepsIcon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_StepsIcon, -8);
    lv_obj_set_y(ui_StepsIcon, 8);
    lv_obj_set_align(ui_StepsIcon, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_StepsIcon, "");
    lv_obj_set_style_text_color(ui_StepsIcon, lv_color_hex(0x33D9B2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StepsIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StepsIcon, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Steps_Value1 = lv_label_create(ui_Steps_Panel1);
    lv_obj_set_width(ui_Steps_Value1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Steps_Value1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Steps_Value1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Steps_Value1, "2586");
    lv_obj_set_style_text_font(ui_Steps_Value1, &ui_font_Numbers42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StepsLabel2 = lv_label_create(ui_Steps_Panel1);
    lv_obj_set_width(ui_StepsLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_StepsLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_StepsLabel2, 0);
    lv_obj_set_y(ui_StepsLabel2, 50);
    lv_obj_set_align(ui_StepsLabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_StepsLabel2, "Steps today");
    lv_obj_set_style_text_color(ui_StepsLabel2, lv_color_hex(0x3E47A3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StepsLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StepsLabel2, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Steps, ui_event_Steps, LV_EVENT_ALL, NULL);

}
void ui_Heart_screen_init(void)
{
    ui_Heart = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Heart, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Heart, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Heart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Steps_Panel2 = lv_obj_create(ui_Heart);
    lv_obj_set_width(ui_Steps_Panel2, lv_pct(100));
    lv_obj_set_height(ui_Steps_Panel2, lv_pct(100));
    lv_obj_set_align(ui_Steps_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Steps_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Steps_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Steps_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Steps_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Steps_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Steps_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Steps_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Steps_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HeartLabel2 = lv_label_create(ui_Steps_Panel2);
    lv_obj_set_width(ui_HeartLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HeartLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HeartLabel2, 5);
    lv_obj_set_y(ui_HeartLabel2, 13);
    lv_label_set_text(ui_HeartLabel2, "Heart rate");
    lv_obj_set_style_text_color(ui_HeartLabel2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HeartLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HeartLabel2, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HeartIcon1 = lv_label_create(ui_Steps_Panel2);
    lv_obj_set_width(ui_HeartIcon1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HeartIcon1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HeartIcon1, -8);
    lv_obj_set_y(ui_HeartIcon1, 8);
    lv_obj_set_align(ui_HeartIcon1, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_HeartIcon1, "");
    lv_obj_set_style_text_color(ui_HeartIcon1, lv_color_hex(0x33D9B2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HeartIcon1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HeartIcon1, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HRValue2 = lv_label_create(ui_Steps_Panel2);
    lv_obj_set_width(ui_HRValue2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HRValue2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HRValue2, 0);
    lv_obj_set_y(ui_HRValue2, -35);
    lv_obj_set_align(ui_HRValue2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HRValue2, "85");
    lv_obj_set_style_text_color(ui_HRValue2, lv_color_hex(0xDB080F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HRValue2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HRValue2, &ui_font_Numbers42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HRLabel3 = lv_label_create(ui_Steps_Panel2);
    lv_obj_set_width(ui_HRLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HRLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HRLabel3, 54);
    lv_obj_set_y(ui_HRLabel3, -33);
    lv_obj_set_align(ui_HRLabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HRLabel3, "bpm");
    lv_obj_set_style_text_color(ui_HRLabel3, lv_color_hex(0x3E47A3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HRLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HRLabel3, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chart2 = lv_chart_create(ui_Heart);
    lv_obj_set_width(ui_Chart2, 185);
    lv_obj_set_height(ui_Chart2, 85);
    lv_obj_set_x(ui_Chart2, 15);
    lv_obj_set_y(ui_Chart2, 46);
    lv_obj_set_align(ui_Chart2, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_Chart2, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_Chart2, 6);
    lv_chart_set_range(ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, 40, 100);
    lv_chart_set_range(ui_Chart2, LV_CHART_AXIS_SECONDARY_Y, 40, 100);
    lv_chart_set_axis_tick(ui_Chart2, LV_CHART_AXIS_PRIMARY_X, 10, 5, 5, 2, true, 50);
    lv_chart_set_axis_tick(ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 2, true, 50);
    lv_chart_series_t * ui_Chart2_series_1 = lv_chart_add_series(ui_Chart2, lv_color_hex(0xDB1111),
                                                                 LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_Chart2_series_1_array[] = { 67, 72, 80, 79, 87, 85 };
    lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_1, ui_Chart2_series_1_array);
    lv_obj_set_style_bg_color(ui_Chart2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Chart2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Heart, ui_event_Heart, LV_EVENT_ALL, NULL);

}
void ui_Status_screen_init(void)
{
    ui_Status = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Status, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Status_Panel = lv_obj_create(ui_Status);
    lv_obj_set_width(ui_Status_Panel, lv_pct(100));
    lv_obj_set_height(ui_Status_Panel, lv_pct(100));
    lv_obj_set_align(ui_Status_Panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Status_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Status_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Status_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Status_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Status_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Status_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Status_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Status_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StatusLabel1 = lv_label_create(ui_Status_Panel);
    lv_obj_set_width(ui_StatusLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_StatusLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_StatusLabel1, 5);
    lv_obj_set_y(ui_StatusLabel1, 13);
    lv_label_set_text(ui_StatusLabel1, "Status");
    lv_obj_set_style_text_color(ui_StatusLabel1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StatusLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StatusLabel1, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BattStatus = lv_label_create(ui_Status);
    lv_obj_set_width(ui_BattStatus, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BattStatus, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_BattStatus, 0);
    lv_obj_set_y(ui_BattStatus, -30);
    lv_obj_set_align(ui_BattStatus, LV_ALIGN_CENTER);
    lv_label_set_text(ui_BattStatus, "0.0 mV");

    ui_ChargingStatus = lv_label_create(ui_Status);
    lv_obj_set_width(ui_ChargingStatus, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargingStatus, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChargingStatus, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChargingStatus, "Discharging");

    lv_obj_add_event_cb(ui_Status, ui_event_Status, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Clock_screen_init();
    ui_Config_screen_init();
    ui_About_screen_init();
    ui_Backlight_screen_init();
    ui_SetTime_screen_init();
    ui_SetDate_screen_init();
    ui_Messages_screen_init();
    ui_Steps_screen_init();
    ui_Heart_screen_init();
    ui_Status_screen_init();
    lv_disp_load_scr(ui_Clock);
}
