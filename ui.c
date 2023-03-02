// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.3
// PROJECT: Pinetime

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

lv_obj_t *ui_Clock02_Panel3;
lv_obj_t *ui_Clock02_Minute3;
lv_obj_t *ui_Clock02_Hour3;
lv_obj_t *ui_Clock02Seconds1;
lv_obj_t *ui_Clock02DatePanel3;
lv_obj_t *ui_Clock02_Date8;
lv_obj_t *ui_Clock02_Date10;
lv_obj_t *ui_Clock02BlaPanel3;
lv_obj_t *ui_Clock02Ble3;
lv_obj_t *ui_Clock02PwrPanel3;
lv_obj_t *ui_imgPower1;
lv_obj_t *ui_Clock02_Power3;
lv_obj_t *ui_Clock02StepsPanel2;
lv_obj_t *ui_imgWalk1;
lv_obj_t *ui_Clock02_Date12;
lv_obj_t *ui_Clock02HRPanel2;
lv_obj_t *ui_imgHeart1;
lv_obj_t *ui_Clock02_Date13;
lv_obj_t *ui_Clock02MsgPanel1;
lv_obj_t *ui_Clock02Msg1;

lv_obj_t *ui_Steps;
lv_obj_t *ui_Steps_Panel1;
lv_obj_t *ui_ImageW1;
lv_obj_t *ui_Panel4;
lv_obj_t *ui_Steps_Value1;
lv_obj_t *ui_StepsToday;
lv_obj_t *ui_PanelGoal;
lv_obj_t *ui_StepsGoalLbl;
lv_obj_t *ui_StepsGoal;

lv_obj_t *ui_Heart_Panel;
lv_obj_t *ui_HeartIcon;
lv_obj_t *ui_HeartValue;
lv_obj_t *ui_HRValue;
lv_obj_t *ui_HRbpmLabel;
lv_obj_t *ui_ChartHeart;

lv_obj_t *ui_Messages;
lv_obj_t *ui_Messages_Panel;
lv_obj_t *ui_MsgNoNotif;
lv_obj_t *ui_Messages_Label5;
lv_obj_t *ui_Notification_Icon;
lv_obj_t *ui_Messages_Label6;
lv_obj_t *ui_PanelListNotf;
lv_obj_t *ui_NotifHeader;
lv_obj_t *ui_NotifHeadTitle;
lv_obj_t *ui_NotifHeadTime;
lv_obj_t *ui_PanelNotif;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif


void ui_Clock02_screen_init(lv_obj_t *tile) {

  ui_Clock02_Panel3 = lv_obj_create(tile);

  lv_obj_set_width(ui_Clock02_Panel3, lv_pct(100));
  lv_obj_set_height(ui_Clock02_Panel3, lv_pct(100));
  lv_obj_set_align(ui_Clock02_Panel3, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Clock02_Panel3, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_scrollbar_mode(ui_Clock02_Panel3, LV_SCROLLBAR_MODE_OFF);
  lv_obj_set_style_radius(ui_Clock02_Panel3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Clock02_Panel3, lv_color_hex(0x570000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Clock02_Panel3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Clock02_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Clock02_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Clock02_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Clock02_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02_Minute3 = lv_label_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02_Minute3, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Clock02_Minute3, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Clock02_Minute3, 74);
  lv_obj_set_y(ui_Clock02_Minute3, 0);
  lv_obj_set_align(ui_Clock02_Minute3, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Clock02_Minute3, "00");
  lv_obj_set_style_text_color(ui_Clock02_Minute3, lv_color_hex(0x00BAD9), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Clock02_Minute3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Clock02_Minute3, &ui_font_Numbers64, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02_Hour3 = lv_label_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02_Hour3, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Clock02_Hour3, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Clock02_Hour3, -44);
  lv_obj_set_y(ui_Clock02_Hour3, -21);
  lv_obj_set_align(ui_Clock02_Hour3, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Clock02_Hour3, "00");
  lv_obj_set_style_text_font(ui_Clock02_Hour3, &ui_font_BigNumbers, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02Seconds1 = lv_bar_create(ui_Clock02_Panel3);
  lv_bar_set_range(ui_Clock02Seconds1, 0, 59);
  lv_bar_set_value(ui_Clock02Seconds1, 30, LV_ANIM_OFF);
  lv_obj_set_width(ui_Clock02Seconds1, 201);
  lv_obj_set_height(ui_Clock02Seconds1, 12);
  lv_obj_set_x(ui_Clock02Seconds1, 0);
  lv_obj_set_y(ui_Clock02Seconds1, 48);
  lv_obj_set_align(ui_Clock02Seconds1, LV_ALIGN_CENTER);

  lv_obj_set_style_bg_color(ui_Clock02Seconds1, lv_color_hex(0xF2FF49), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02Seconds1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

  ui_Clock02DatePanel3 = lv_obj_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02DatePanel3, 105);
  lv_obj_set_height(ui_Clock02DatePanel3, 32);
  lv_obj_set_x(ui_Clock02DatePanel3, -4);
  lv_obj_set_y(ui_Clock02DatePanel3, 6);
  lv_obj_set_align(ui_Clock02DatePanel3, LV_ALIGN_TOP_RIGHT);
  lv_obj_set_flex_flow(ui_Clock02DatePanel3, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_Clock02DatePanel3, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Clock02DatePanel3, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_Clock02DatePanel3, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Clock02DatePanel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02DatePanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Clock02DatePanel3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Clock02DatePanel3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Clock02DatePanel3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Clock02DatePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Clock02DatePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_row(ui_Clock02DatePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_column(ui_Clock02DatePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02_Date8 = lv_label_create(ui_Clock02DatePanel3);
  lv_obj_set_width(ui_Clock02_Date8, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Clock02_Date8, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Clock02_Date8, 10);
  lv_obj_set_y(ui_Clock02_Date8, -5);
  lv_obj_set_align(ui_Clock02_Date8, LV_ALIGN_BOTTOM_LEFT);
  lv_label_set_text(ui_Clock02_Date8, "06");
  lv_obj_set_style_text_color(ui_Clock02_Date8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Clock02_Date8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Clock02_Date8, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02_Date10 = lv_label_create(ui_Clock02DatePanel3);
  lv_obj_set_width(ui_Clock02_Date10, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Clock02_Date10, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Clock02_Date10, 10);
  lv_obj_set_y(ui_Clock02_Date10, -5);
  lv_obj_set_align(ui_Clock02_Date10, LV_ALIGN_BOTTOM_LEFT);
  lv_label_set_text(ui_Clock02_Date10, "SUN");
  lv_obj_set_style_text_color(ui_Clock02_Date10, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Clock02_Date10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Clock02_Date10, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02BlaPanel3 = lv_obj_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02BlaPanel3, 40);
  lv_obj_set_height(ui_Clock02BlaPanel3, 32);
  lv_obj_set_x(ui_Clock02BlaPanel3, 93);
  lv_obj_set_y(ui_Clock02BlaPanel3, -45);
  lv_obj_set_align(ui_Clock02BlaPanel3, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_Clock02BlaPanel3, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_Clock02BlaPanel3, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Clock02BlaPanel3, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Clock02BlaPanel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02BlaPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Clock02BlaPanel3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Clock02BlaPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Clock02BlaPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Clock02BlaPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Clock02BlaPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_row(ui_Clock02BlaPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_column(ui_Clock02BlaPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02Ble3 = lv_img_create(ui_Clock02BlaPanel3);
  lv_img_set_src(ui_Clock02Ble3, &ui_img_bluetooth_png);
  lv_obj_set_width(ui_Clock02Ble3, LV_SIZE_CONTENT);   /// 15
  lv_obj_set_height(ui_Clock02Ble3, LV_SIZE_CONTENT);  /// 19
  lv_obj_set_x(ui_Clock02Ble3, 0);
  lv_obj_set_y(ui_Clock02Ble3, -8);
  lv_obj_set_align(ui_Clock02Ble3, LV_ALIGN_BOTTOM_MID);
  lv_obj_add_flag(ui_Clock02Ble3, LV_OBJ_FLAG_HIDDEN);                                                                                                                                                                                                          /// Flags
  lv_obj_clear_flag(ui_Clock02Ble3, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags

  ui_Clock02PwrPanel3 = lv_obj_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02PwrPanel3, 105);
  lv_obj_set_height(ui_Clock02PwrPanel3, 32);
  lv_obj_set_x(ui_Clock02PwrPanel3, 4);
  lv_obj_set_y(ui_Clock02PwrPanel3, 6);
  lv_obj_set_flex_flow(ui_Clock02PwrPanel3, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_Clock02PwrPanel3, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Clock02PwrPanel3, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_Clock02PwrPanel3, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Clock02PwrPanel3, lv_color_hex(0x005308), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02PwrPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Clock02PwrPanel3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Clock02PwrPanel3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Clock02PwrPanel3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Clock02PwrPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Clock02PwrPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_row(ui_Clock02PwrPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_column(ui_Clock02PwrPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_imgPower1 = lv_img_create(ui_Clock02PwrPanel3);
  lv_img_set_src(ui_imgPower1, &ui_img_power_png);
  lv_obj_set_width(ui_imgPower1, LV_SIZE_CONTENT);   /// 22
  lv_obj_set_height(ui_imgPower1, LV_SIZE_CONTENT);  /// 22
  lv_obj_set_align(ui_imgPower1, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_imgPower1, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_imgPower1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_Clock02_Power3 = lv_label_create(ui_Clock02PwrPanel3);
  lv_obj_set_width(ui_Clock02_Power3, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Clock02_Power3, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Clock02_Power3, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Clock02_Power3, "100 %");
  lv_obj_set_style_text_color(ui_Clock02_Power3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Clock02_Power3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Clock02_Power3, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02StepsPanel2 = lv_obj_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02StepsPanel2, 110);
  lv_obj_set_height(ui_Clock02StepsPanel2, 32);
  lv_obj_set_x(ui_Clock02StepsPanel2, 4);
  lv_obj_set_y(ui_Clock02StepsPanel2, -6);
  lv_obj_set_align(ui_Clock02StepsPanel2, LV_ALIGN_BOTTOM_LEFT);
  lv_obj_set_flex_flow(ui_Clock02StepsPanel2, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_Clock02StepsPanel2, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Clock02StepsPanel2, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_Clock02StepsPanel2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Clock02StepsPanel2, lv_color_hex(0x003CBD), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02StepsPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Clock02StepsPanel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Clock02StepsPanel2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Clock02StepsPanel2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Clock02StepsPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Clock02StepsPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_row(ui_Clock02StepsPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_column(ui_Clock02StepsPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_imgWalk1 = lv_img_create(ui_Clock02StepsPanel2);
  lv_img_set_src(ui_imgWalk1, &ui_img_walk_png);
  lv_obj_set_width(ui_imgWalk1, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_imgWalk1, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_imgWalk1, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_imgWalk1, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_imgWalk1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_Clock02_Date12 = lv_label_create(ui_Clock02StepsPanel2);
  lv_obj_set_width(ui_Clock02_Date12, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Clock02_Date12, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Clock02_Date12, 10);
  lv_obj_set_y(ui_Clock02_Date12, -5);
  lv_obj_set_align(ui_Clock02_Date12, LV_ALIGN_BOTTOM_LEFT);
  lv_label_set_text(ui_Clock02_Date12, "12 586");
  lv_obj_set_style_text_color(ui_Clock02_Date12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Clock02_Date12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Clock02_Date12, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02HRPanel2 = lv_obj_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02HRPanel2, 100);
  lv_obj_set_height(ui_Clock02HRPanel2, 32);
  lv_obj_set_x(ui_Clock02HRPanel2, -4);
  lv_obj_set_y(ui_Clock02HRPanel2, -6);
  lv_obj_set_align(ui_Clock02HRPanel2, LV_ALIGN_BOTTOM_RIGHT);
  lv_obj_set_flex_flow(ui_Clock02HRPanel2, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_Clock02HRPanel2, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Clock02HRPanel2, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_Clock02HRPanel2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Clock02HRPanel2, lv_color_hex(0xB40000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02HRPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Clock02HRPanel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Clock02HRPanel2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Clock02HRPanel2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Clock02HRPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Clock02HRPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_row(ui_Clock02HRPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_column(ui_Clock02HRPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_imgHeart1 = lv_img_create(ui_Clock02HRPanel2);
  lv_img_set_src(ui_imgHeart1, &ui_img_heart_png);
  lv_obj_set_width(ui_imgHeart1, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_imgHeart1, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_imgHeart1, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_imgHeart1, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_imgHeart1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_Clock02_Date13 = lv_label_create(ui_Clock02HRPanel2);
  lv_obj_set_width(ui_Clock02_Date13, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Clock02_Date13, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Clock02_Date13, 10);
  lv_obj_set_y(ui_Clock02_Date13, -5);
  lv_obj_set_align(ui_Clock02_Date13, LV_ALIGN_BOTTOM_LEFT);
  lv_label_set_text(ui_Clock02_Date13, "87");
  lv_obj_set_style_text_font(ui_Clock02_Date13, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02MsgPanel1 = lv_obj_create(ui_Clock02_Panel3);
  lv_obj_set_width(ui_Clock02MsgPanel1, 40);
  lv_obj_set_height(ui_Clock02MsgPanel1, 32);
  lv_obj_set_x(ui_Clock02MsgPanel1, 54);
  lv_obj_set_y(ui_Clock02MsgPanel1, -45);
  lv_obj_set_align(ui_Clock02MsgPanel1, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_Clock02MsgPanel1, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_Clock02MsgPanel1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Clock02MsgPanel1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Clock02MsgPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Clock02MsgPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Clock02MsgPanel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Clock02MsgPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Clock02MsgPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Clock02MsgPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Clock02MsgPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_row(ui_Clock02MsgPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_column(ui_Clock02MsgPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Clock02Msg1 = lv_img_create(ui_Clock02MsgPanel1);
  lv_img_set_src(ui_Clock02Msg1, &ui_img_message_png);
  lv_obj_set_width(ui_Clock02Msg1, LV_SIZE_CONTENT);   /// 15
  lv_obj_set_height(ui_Clock02Msg1, LV_SIZE_CONTENT);  /// 19
  lv_obj_set_x(ui_Clock02Msg1, -2);
  lv_obj_set_y(ui_Clock02Msg1, -8);
  lv_obj_set_align(ui_Clock02Msg1, LV_ALIGN_BOTTOM_MID);
  lv_obj_add_flag(ui_Clock02Msg1, LV_OBJ_FLAG_HIDDEN);                                                                                                                                                                                                          /// Flags
  lv_obj_clear_flag(ui_Clock02Msg1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
}

void ui_Steps_screen_init(lv_obj_t *tile) {

  ui_Steps_Panel1 = lv_obj_create(tile);

  lv_obj_set_width(ui_Steps_Panel1, lv_pct(100));
  lv_obj_set_height(ui_Steps_Panel1, lv_pct(100));
  lv_obj_set_align(ui_Steps_Panel1, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Steps_Panel1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Steps_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Steps_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Steps_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Steps_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_ImageW1 = lv_img_create(ui_Steps_Panel1);
  lv_img_set_src(ui_ImageW1, &ui_img_walk1_png);
  lv_obj_set_width(ui_ImageW1, LV_SIZE_CONTENT);   /// 32
  lv_obj_set_height(ui_ImageW1, LV_SIZE_CONTENT);  /// 64
  lv_obj_set_x(ui_ImageW1, 0);
  lv_obj_set_y(ui_ImageW1, -28);
  lv_obj_set_align(ui_ImageW1, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_ImageW1, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_ImageW1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_Panel4 = lv_obj_create(ui_Steps_Panel1);
  lv_obj_set_width(ui_Panel4, 206);
  lv_obj_set_height(ui_Panel4, 49);
  lv_obj_set_x(ui_Panel4, 0);
  lv_obj_set_y(ui_Panel4, 35);
  lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_Panel4, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_Panel4, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_Panel4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0x003CBD), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Panel4, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Steps_Value1 = lv_label_create(ui_Panel4);
  lv_obj_set_width(ui_Steps_Value1, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Steps_Value1, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Steps_Value1, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Steps_Value1, "0");
  lv_obj_set_style_text_font(ui_Steps_Value1, &ui_font_Numbers42, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_StepsToday = lv_label_create(ui_Steps_Panel1);
  lv_obj_set_width(ui_StepsToday, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_StepsToday, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_StepsToday, 0);
  lv_obj_set_y(ui_StepsToday, 16);
  lv_obj_set_align(ui_StepsToday, LV_ALIGN_TOP_MID);
  lv_label_set_text(ui_StepsToday, "Steps today");
  lv_obj_set_style_text_color(ui_StepsToday, lv_color_hex(0x10837F), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_StepsToday, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_StepsToday, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_PanelGoal = lv_obj_create(ui_Steps_Panel1);
  lv_obj_set_height(ui_PanelGoal, 28);
  lv_obj_set_width(ui_PanelGoal, lv_pct(100));
  lv_obj_set_x(ui_PanelGoal, 0);
  lv_obj_set_y(ui_PanelGoal, -3);
  lv_obj_set_align(ui_PanelGoal, LV_ALIGN_BOTTOM_MID);
  lv_obj_set_flex_flow(ui_PanelGoal, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_PanelGoal, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_PanelGoal, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_PanelGoal, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_PanelGoal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_PanelGoal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_PanelGoal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_PanelGoal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_PanelGoal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_PanelGoal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_StepsGoalLbl = lv_label_create(ui_PanelGoal);
  lv_obj_set_width(ui_StepsGoalLbl, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_StepsGoalLbl, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_StepsGoalLbl, LV_ALIGN_CENTER);
  lv_label_set_text(ui_StepsGoalLbl, "Goal for today");
  lv_obj_set_style_text_color(ui_StepsGoalLbl, lv_color_hex(0x343434), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_StepsGoalLbl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_StepsGoalLbl, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_StepsGoal = lv_label_create(ui_PanelGoal);
  lv_obj_set_width(ui_StepsGoal, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_StepsGoal, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_StepsGoal, LV_ALIGN_CENTER);
  lv_label_set_text(ui_StepsGoal, "20 000");
  lv_obj_set_style_text_color(ui_StepsGoal, lv_color_hex(0x505050), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_StepsGoal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_StepsGoal, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_Messages_screen_init(lv_obj_t *tile) {

  ui_Messages_Panel = lv_obj_create(tile);
  lv_obj_set_width(ui_Messages_Panel, lv_pct(100));
  lv_obj_set_height(ui_Messages_Panel, lv_pct(100));
  lv_obj_set_align(ui_Messages_Panel, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Messages_Panel, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Messages_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Messages_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Messages_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Messages_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_MsgNoNotif = lv_obj_create(ui_Messages_Panel);
  lv_obj_set_width(ui_MsgNoNotif, lv_pct(100));
  lv_obj_set_height(ui_MsgNoNotif, lv_pct(100));
  lv_obj_set_align(ui_MsgNoNotif, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_MsgNoNotif, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(ui_MsgNoNotif, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_EVENLY);
  lv_obj_clear_flag(ui_MsgNoNotif, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_bg_color(ui_MsgNoNotif, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_MsgNoNotif, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_MsgNoNotif, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Messages_Label5 = lv_label_create(ui_MsgNoNotif);
  lv_obj_set_width(ui_Messages_Label5, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Messages_Label5, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Messages_Label5, LV_ALIGN_TOP_MID);
  lv_label_set_text(ui_Messages_Label5, "Notifications");
  lv_obj_set_style_text_color(ui_Messages_Label5, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Messages_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Messages_Label5, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Notification_Icon = lv_label_create(ui_MsgNoNotif);
  lv_obj_set_width(ui_Notification_Icon, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Notification_Icon, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Notification_Icon, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Notification_Icon, "");
  lv_obj_set_style_text_color(ui_Notification_Icon, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Notification_Icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Notification_Icon, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Messages_Label6 = lv_label_create(ui_MsgNoNotif);
  lv_obj_set_width(ui_Messages_Label6, lv_pct(95));
  lv_obj_set_height(ui_Messages_Label6, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Messages_Label6, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Messages_Label6, "You don't have new notifications...");
  lv_obj_set_style_text_align(ui_Messages_Label6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Messages_Label6, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_PanelListNotf = lv_obj_create(ui_Messages_Panel);
  lv_obj_set_width(ui_PanelListNotf, lv_pct(100));
  lv_obj_set_height(ui_PanelListNotf, lv_pct(100));
  lv_obj_set_align(ui_PanelListNotf, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_PanelListNotf, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_EVENT_BUBBLE);
  //lv_obj_clear_flag(ui_PanelListNotf, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_scrollbar_mode(ui_PanelListNotf, LV_SCROLLBAR_MODE_OFF);
  lv_obj_set_style_bg_color(ui_PanelListNotf, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_PanelListNotf, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_PanelListNotf, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_PanelListNotf, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_PanelListNotf, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_PanelListNotf, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_PanelListNotf, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_NotifHeader = lv_obj_create(ui_PanelListNotf);
  lv_obj_set_height(ui_NotifHeader, 24);
  lv_obj_set_width(ui_NotifHeader, lv_pct(100));
  lv_obj_set_align(ui_NotifHeader, LV_ALIGN_TOP_MID);
  lv_obj_set_flex_flow(ui_NotifHeader, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_NotifHeader, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_NotifHeader, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_radius(ui_NotifHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_NotifHeader, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_NotifHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_NotifHeader, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_NotifHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_NotifHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_NotifHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_NotifHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_NotifHeadTitle = lv_label_create(ui_NotifHeader);
  lv_obj_set_width(ui_NotifHeadTitle, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_NotifHeadTitle, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_NotifHeadTitle, LV_ALIGN_CENTER);
  lv_label_set_text(ui_NotifHeadTitle, "Notifications");
  lv_obj_set_style_text_font(ui_NotifHeadTitle, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_NotifHeadTime = lv_label_create(ui_NotifHeader);
  lv_obj_set_width(ui_NotifHeadTime, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_NotifHeadTime, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_NotifHeadTime, LV_ALIGN_CENTER);
  lv_label_set_text(ui_NotifHeadTime, "00:00");
  lv_obj_set_style_text_font(ui_NotifHeadTime, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_PanelNotif = lv_obj_create(ui_PanelListNotf);
  lv_obj_set_width(ui_PanelNotif, lv_pct(100));
  lv_obj_set_height(ui_PanelNotif, lv_pct(88));
  lv_obj_set_x(ui_PanelNotif, 0);
  lv_obj_set_y(ui_PanelNotif, 14);
  lv_obj_set_align(ui_PanelNotif, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_PanelNotif, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_flow(ui_PanelNotif, LV_FLEX_FLOW_COLUMN_REVERSE);
  lv_obj_set_flex_align(ui_PanelNotif, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
  //lv_obj_clear_flag(ui_PanelNotif, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE);  /// Flags
  lv_obj_set_scroll_dir(ui_PanelNotif, LV_DIR_VER);
  lv_obj_set_style_bg_color(ui_PanelNotif, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_PanelNotif, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_PanelNotif, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_PanelNotif, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_PanelNotif, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_PanelNotif, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_PanelNotif, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}


void ui_Heart_screen_init(lv_obj_t *tile) {

  ui_Heart_Panel = lv_obj_create(tile);
  lv_obj_set_width(ui_Heart_Panel, lv_pct(100));
  lv_obj_set_height(ui_Heart_Panel, lv_pct(100));
  lv_obj_set_align(ui_Heart_Panel, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Heart_Panel, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Heart_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Heart_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Heart_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Heart_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Heart_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Heart_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Heart_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_HeartIcon = lv_img_create(ui_Heart_Panel);
  lv_img_set_src(ui_HeartIcon, &ui_img_heart_pulse_png);
  lv_obj_set_width(ui_HeartIcon, LV_SIZE_CONTENT);   /// 46
  lv_obj_set_height(ui_HeartIcon, LV_SIZE_CONTENT);  /// 46
  lv_obj_set_x(ui_HeartIcon, 0);
  lv_obj_set_y(ui_HeartIcon, 5);
  lv_obj_set_align(ui_HeartIcon, LV_ALIGN_TOP_MID);
  lv_obj_add_flag(ui_HeartIcon, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_HeartIcon, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_HeartValue = lv_obj_create(ui_Heart_Panel);
  lv_obj_set_width(ui_HeartValue, 180);
  lv_obj_set_height(ui_HeartValue, 40);
  lv_obj_set_x(ui_HeartValue, 0);
  lv_obj_set_y(ui_HeartValue, -23);
  lv_obj_set_align(ui_HeartValue, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_HeartValue, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_HeartValue, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_HeartValue, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_HeartValue, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_HeartValue, lv_color_hex(0xB40000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_HeartValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_HeartValue, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_HRValue = lv_label_create(ui_HeartValue);
  lv_obj_set_width(ui_HRValue, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_HRValue, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_HRValue, -11);
  lv_obj_set_y(ui_HRValue, -57);
  lv_obj_set_align(ui_HRValue, LV_ALIGN_CENTER);
  lv_label_set_text(ui_HRValue, "85");
  lv_obj_set_style_text_color(ui_HRValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_HRValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_HRValue, &ui_font_Numbers42, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_HRbpmLabel = lv_label_create(ui_HeartValue);
  lv_obj_set_width(ui_HRbpmLabel, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_HRbpmLabel, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_HRbpmLabel, 47);
  lv_obj_set_y(ui_HRbpmLabel, -56);
  lv_obj_set_align(ui_HRbpmLabel, LV_ALIGN_CENTER);
  lv_label_set_text(ui_HRbpmLabel, "bpm");
  lv_obj_set_style_text_color(ui_HRbpmLabel, lv_color_hex(0x00BADE), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_HRbpmLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_HRbpmLabel, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_ChartHeart = lv_chart_create(ui_Heart_Panel);
  lv_obj_set_height(ui_ChartHeart, 96);
  lv_obj_set_width(ui_ChartHeart, lv_pct(100));
  lv_obj_set_x(ui_ChartHeart, 0);
  lv_obj_set_y(ui_ChartHeart, -10);
  lv_obj_set_align(ui_ChartHeart, LV_ALIGN_BOTTOM_MID);
  lv_chart_set_type(ui_ChartHeart, LV_CHART_TYPE_LINE);
  lv_chart_set_point_count(ui_ChartHeart, 6);
  lv_chart_set_range(ui_ChartHeart, LV_CHART_AXIS_PRIMARY_Y, 40, 100);
  lv_chart_set_range(ui_ChartHeart, LV_CHART_AXIS_SECONDARY_Y, 40, 100);
  lv_chart_set_axis_tick(ui_ChartHeart, LV_CHART_AXIS_PRIMARY_X, 10, 5, 5, 2, false, 50);
  lv_chart_set_axis_tick(ui_ChartHeart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 2, false, 50);
  lv_chart_series_t *ui_ChartHeart_series_1 = lv_chart_add_series(ui_ChartHeart, lv_color_hex(0xDB1111),
                                                                  LV_CHART_AXIS_PRIMARY_Y);
  static lv_coord_t ui_ChartHeart_series_1_array[] = { 67, 72, 80, 79, 87, 85 };
  lv_chart_set_ext_y_array(ui_ChartHeart, ui_ChartHeart_series_1, ui_ChartHeart_series_1_array);
  lv_obj_set_style_bg_color(ui_ChartHeart, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_ChartHeart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_ChartHeart, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
}
