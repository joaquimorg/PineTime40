#include "PineTime.h"
#include <stdlib.h>

#include "ui.h"
#include "ui_events.h"

#include "smartwatch_ui.h"
#include "notification_obj.h"

#include "fragment_notification.h"
#include "screens.h"

lv_obj_t *root = NULL;
lv_fragment_manager_t *f_manager = NULL;

lv_obj_t *tv;
lv_obj_t *tile1;
lv_obj_t *tile2;
lv_obj_t *tile3;
lv_obj_t *tile4;

lv_obj_t *active_screen;
lv_obj_t *back_screen;

Vector<lv_obj_t *> l_not;

// -----------------------------------------------------------------------------------------------------------------------
// fragment screens

// -----------------------------------------------------------------------------------------------------------------------

uint8_t old_min = 99;
uint8_t old_min_c = 99;
uint8_t old_hour = 99;
uint8_t old_day = 99;

void update_clock(void) {

  lv_obj_t *curr_screen = lv_tileview_get_tile_act(tv);  //lv_scr_act();

  if (curr_screen == NULL) {
    return;
  }

  if (curr_screen == tile2) {
    pinetime.rtctime.get_time();

    lv_bar_set_value(ui_Clock02Seconds1, pinetime.rtctime.seconds(), LV_ANIM_ON);

    if (old_min != pinetime.rtctime.minutes()) {
      //lv_label_set_text_fmt(ui_Clock_Minute, "%02i", pinetime.rtctime.minutes());
      lv_label_set_text_fmt(ui_Clock02_Minute3, "%02i", pinetime.rtctime.minutes());

      if (pinetime.battIsCharging()) {
        lv_label_set_text(ui_Clock02_Power3, "Chr.");
      } else {
        lv_label_set_text_fmt(ui_Clock02_Power3, "%i%%", pinetime.mvToPercent(pinetime.readVBAT()));
      }

      old_min = pinetime.rtctime.minutes();
    }
    if (old_hour != pinetime.rtctime.hours()) {
      //lv_label_set_text_fmt(ui_Clock_Hour, "%02i", pinetime.rtctime.hours());
      lv_label_set_text_fmt(ui_Clock02_Hour3, "%02i", pinetime.rtctime.hours());
      old_hour = pinetime.rtctime.hours();
    }
    if (old_day != pinetime.rtctime.week()) {
      //update_day();
      lv_label_set_text_fmt(ui_Clock02_Date8, "%02i", pinetime.rtctime.day());
      lv_label_set_text_fmt(ui_Clock02_Date10, "%s", pinetime.rtctime.get_days_short());
      old_day = pinetime.rtctime.week();
    }
    if (pinetime.bleIsConnected()) {
      lv_obj_clear_flag(ui_Clock02Ble3, LV_OBJ_FLAG_HIDDEN);
    } else {
      lv_obj_add_flag(ui_Clock02Ble3, LV_OBJ_FLAG_HIDDEN);
    }

    lv_label_set_text_fmt(ui_Clock02_Date12, "%i", pinetime.getStepCount());

  } else {
    old_min = 99;
    old_min_c = 99;
    old_hour = 99;
    old_day = 99;
  }

  if (curr_screen == tile1) {
    lv_label_set_text_fmt(ui_NotifHeadTime, "%02i:%02i", pinetime.rtctime.hours(), pinetime.rtctime.minutes());
    if (!lv_obj_has_flag(ui_Clock02Msg1, LV_OBJ_FLAG_HIDDEN)) {
      lv_obj_add_flag(ui_Clock02Msg1, LV_OBJ_FLAG_HIDDEN);
    }
  }

  if (curr_screen == tile3) {
    lv_label_set_text_fmt(ui_Steps_Value1, "%i", pinetime.getStepCount());
  }
}

//
void show_notification(Notification *notification) {
  lv_fragment_t *fragment = lv_fragment_create(&notification_cls, notification);
  lv_fragment_manager_push(f_manager, fragment, &root);
}

static void ui_event_notification(lv_event_t *e) {
  lv_obj_t *o_not = lv_event_get_target(e);

  int notPos = l_not.Find(o_not);
  if (notPos != -1) {
    Notification noti = pinetime.getNotification(notPos);
    show_notification(&noti);
  } else {
    Serial.println(">>> notification not found...");
  }
}
//
void update_notification() {
  if (pinetime.getNotificationCount() > 0) {

    if (!lv_obj_has_flag(ui_MsgNoNotif, LV_OBJ_FLAG_HIDDEN)) {
      lv_obj_add_flag(ui_MsgNoNotif, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_PanelListNotf, LV_OBJ_FLAG_HIDDEN);
    }
    lv_obj_clear_flag(ui_Clock02Msg1, LV_OBJ_FLAG_HIDDEN);

    if (l_not.Size() == 4) {
      if (l_not[0]) {
        lv_obj_del(l_not[0]);
      }
      l_not.Erase(0);
    }

    Notification noti = pinetime.getNotification(pinetime.getNotificationCount() - 1);
    lv_obj_t *o_not = notification_create_obj(ui_PanelNotif, &noti);
    show_notification(&noti);

    lv_obj_add_event_cb(o_not, ui_event_notification, LV_EVENT_CLICKED, NULL);

    l_not.PushBack(o_not);

    //lv_obj_set_tile_id(tv, 0, 0, LV_ANIM_ON);

  } else {
    if (!lv_obj_has_flag(ui_PanelListNotf, LV_OBJ_FLAG_HIDDEN)) {
      lv_obj_add_flag(ui_PanelListNotf, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_MsgNoNotif, LV_OBJ_FLAG_HIDDEN);
    }
    lv_obj_add_flag(ui_Clock02Msg1, LV_OBJ_FLAG_HIDDEN);
  }
}
// -----------------------------------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------------------------------------------

void timerAnim(lv_timer_t *timer) {

  static uint8_t anim = 1;

  lv_obj_t *curr_screen = lv_tileview_get_tile_act(tv);

  if (curr_screen == NULL) {
    return;
  }

  if (curr_screen == tile3) {
    if (anim == 1) lv_img_set_src(ui_ImageW1, &ui_img_walk1_png);
    if (anim == 2) lv_img_set_src(ui_ImageW1, &ui_img_walk2_png);
    if (anim == 3) lv_img_set_src(ui_ImageW1, &ui_img_walk3_png);
    if (anim == 4) lv_img_set_src(ui_ImageW1, &ui_img_walk4_png);
    anim++;
    if (anim > 4) anim = 1;
  }
}

// -----------------------------------------------------------------------------------------------------------------------
// base event for root screen
//
static void ui_event_root(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);

  if (event_code == LV_EVENT_GESTURE) {
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());

    if (dir == LV_DIR_RIGHT) {
      uint8_t stack_size = lv_fragment_manager_get_stack_size(f_manager);
      if (stack_size > 0) {
        lv_fragment_manager_pop(f_manager);
      }
    }

    if (dir == LV_DIR_BOTTOM) {
      //show_notification();
    }
    /*if (dir == LV_DIR_LEFT) {
    }
    if (dir == LV_DIR_TOP) {
    }*/
  }

  if (event_code == LV_EVENT_DELETE) {
    lv_fragment_manager_t *manager = (lv_fragment_manager_t *)lv_event_get_user_data(e);
    lv_fragment_manager_del(manager);
  }
}

static void ui_event_screen(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
    lv_scr_load_anim(back_screen, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 0, true);
  }
}

lv_obj_t *ui_Config_screen_init(void);

static void ui_event_tile(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  //lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
    Serial.println("LV_DIR_TOP");
  }
  if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
    //Serial.println("LV_DIR_BOTTOM");
    back_screen = lv_scr_act();
    active_screen = ui_Config_screen_init();
    lv_obj_add_event_cb(active_screen, ui_event_screen, LV_EVENT_ALL, NULL);
    lv_scr_load_anim(active_screen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 0, false);
  }
}

// -----------------------------------------------------------------------------------------------------------------------

void smartwatch_ui_init(void) {

  // Set default theme
  lv_disp_t *dispp = lv_disp_get_default();
  lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                            true, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);

  // base root screen
  root = lv_obj_create(lv_scr_act());
  lv_obj_remove_style_all(root);
  lv_obj_set_width(root, lv_pct(100));
  lv_obj_set_height(root, lv_pct(100));
  lv_obj_clear_flag(root, LV_OBJ_FLAG_GESTURE_BUBBLE);


  // Tile view
  tv = lv_tileview_create(root);
  lv_obj_clear_flag(tv, LV_OBJ_FLAG_GESTURE_BUBBLE);
  active_screen = tv;

  lv_obj_set_scrollbar_mode(tv, LV_SCROLLBAR_MODE_OFF);
  lv_obj_add_flag(tv, LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);
  lv_obj_set_style_bg_color(tv, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(tv, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  //Tile1:
  tile1 = lv_tileview_add_tile(tv, 0, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
  lv_obj_set_style_bg_color(tile1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(tile1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  ui_Messages_screen_init(tile1);

  //Tile2:
  tile2 = lv_tileview_add_tile(tv, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
  lv_obj_set_style_bg_color(tile2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(tile2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  ui_Clock02_screen_init(tile2);

  lv_obj_clear_flag(tile2, LV_OBJ_FLAG_GESTURE_BUBBLE);
  lv_obj_add_event_cb(tile2, ui_event_tile, LV_EVENT_ALL, NULL);

  //Tile3:
  tile3 = lv_tileview_add_tile(tv, 2, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
  lv_obj_set_style_bg_color(tile3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(tile3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  ui_Steps_screen_init(tile3);

  //Tile4:
  tile4 = lv_tileview_add_tile(tv, 3, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
  lv_obj_set_style_bg_color(tile4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(tile4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  ui_Heart_screen_init(tile4);

  lv_obj_set_tile_id(tv, 1, 0, LV_ANIM_OFF);

  // Fragment manager
  f_manager = lv_fragment_manager_create(NULL);
  lv_obj_add_event_cb(root, ui_event_root, LV_EVENT_ALL, f_manager);

  // animation  ???
  lv_timer_t *timeranim = lv_timer_create(timerAnim, 200, NULL);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------

lv_obj_t *ui_Config_screen_init(void) {
  lv_obj_t *ui_Config = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_Config, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Config, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Panel = lv_obj_create(ui_Config);
  lv_obj_set_width(ui_Config_Panel, 240);
  lv_obj_set_height(ui_Config_Panel, 240);
  lv_obj_set_align(ui_Config_Panel, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Config_Panel, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Config_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Config_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Config_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Config_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Config_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Config_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Actions_Panel = lv_obj_create(ui_Config_Panel);
  lv_obj_set_width(ui_Config_Actions_Panel, 200);
  lv_obj_set_height(ui_Config_Actions_Panel, 190);
  lv_obj_set_x(ui_Config_Actions_Panel, 0);
  lv_obj_set_y(ui_Config_Actions_Panel, 5);
  lv_obj_set_align(ui_Config_Actions_Panel, LV_ALIGN_TOP_MID);
  lv_obj_set_flex_flow(ui_Config_Actions_Panel, LV_FLEX_FLOW_ROW_WRAP);
  lv_obj_set_flex_align(ui_Config_Actions_Panel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER,
                        LV_FLEX_ALIGN_SPACE_EVENLY);
  lv_obj_clear_flag(ui_Config_Actions_Panel, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Config_Actions_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config_Actions_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Config_Actions_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Button3 = lv_btn_create(ui_Config_Actions_Panel);
  lv_obj_set_width(ui_Config_Button3, 70);
  lv_obj_set_height(ui_Config_Button3, 70);
  lv_obj_set_x(ui_Config_Button3, 45);
  lv_obj_set_y(ui_Config_Button3, -70);
  lv_obj_set_align(ui_Config_Button3, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Config_Button3,
                    LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_radius(ui_Config_Button3, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button3, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button3, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_bg_opa(ui_Config_Button3, 255, LV_PART_MAIN | LV_STATE_PRESSED);

  lv_obj_t *ui_Config_Label2 = lv_label_create(ui_Config_Button3);
  lv_obj_set_width(ui_Config_Label2, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Label2, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Config_Label2, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Config_Label2, "");
  lv_obj_set_style_text_font(ui_Config_Label2, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Button6 = lv_btn_create(ui_Config_Actions_Panel);
  lv_obj_set_width(ui_Config_Button6, 70);
  lv_obj_set_height(ui_Config_Button6, 70);
  lv_obj_set_x(ui_Config_Button6, -45);
  lv_obj_set_y(ui_Config_Button6, -70);
  lv_obj_set_align(ui_Config_Button6, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Config_Button6,
                    LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_radius(ui_Config_Button6, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button6, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button6, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_bg_opa(ui_Config_Button6, 255, LV_PART_MAIN | LV_STATE_PRESSED);

  lv_obj_t *ui_Config_Label8 = lv_label_create(ui_Config_Button6);
  lv_obj_set_width(ui_Config_Label8, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Label8, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Config_Label8, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Config_Label8, "");
  lv_obj_set_style_text_font(ui_Config_Label8, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Button4 = lv_btn_create(ui_Config_Actions_Panel);
  lv_obj_set_width(ui_Config_Button4, 70);
  lv_obj_set_height(ui_Config_Button4, 70);
  lv_obj_set_x(ui_Config_Button4, -45);
  lv_obj_set_y(ui_Config_Button4, 16);
  lv_obj_set_align(ui_Config_Button4, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Config_Button4,
                    LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_radius(ui_Config_Button4, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button4, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button4, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_bg_opa(ui_Config_Button4, 255, LV_PART_MAIN | LV_STATE_PRESSED);

  lv_obj_t *ui_Config_Label3 = lv_label_create(ui_Config_Button4);
  lv_obj_set_width(ui_Config_Label3, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Label3, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Config_Label3, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Config_Label3, "");
  lv_obj_set_style_text_font(ui_Config_Label3, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Button5 = lv_btn_create(ui_Config_Actions_Panel);
  lv_obj_set_width(ui_Config_Button5, 70);
  lv_obj_set_height(ui_Config_Button5, 70);
  lv_obj_set_x(ui_Config_Button5, 45);
  lv_obj_set_y(ui_Config_Button5, 16);
  lv_obj_set_align(ui_Config_Button5, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Config_Button5,
                    LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_radius(ui_Config_Button5, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button5, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_Config_Button5, lv_color_hex(0x48801E), LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_bg_opa(ui_Config_Button5, 255, LV_PART_MAIN | LV_STATE_PRESSED);

  lv_obj_t *ui_Config_Label7 = lv_label_create(ui_Config_Button5);
  lv_obj_set_width(ui_Config_Label7, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Label7, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Config_Label7, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Config_Label7, "");
  lv_obj_set_style_text_font(ui_Config_Label7, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Batt_Icon = lv_label_create(ui_Config_Panel);
  lv_obj_set_width(ui_Config_Batt_Icon, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Batt_Icon, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Config_Batt_Icon, 27);
  lv_obj_set_y(ui_Config_Batt_Icon, -3);
  lv_obj_set_align(ui_Config_Batt_Icon, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_Config_Batt_Icon, "");
  lv_obj_set_style_text_color(ui_Config_Batt_Icon, lv_color_hex(0x017515), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Config_Batt_Icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Config_Batt_Icon, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Time = lv_label_create(ui_Config_Panel);
  lv_obj_set_width(ui_Config_Time, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Time, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Config_Time, 10);
  lv_obj_set_y(ui_Config_Time, -10);
  lv_obj_set_align(ui_Config_Time, LV_ALIGN_BOTTOM_LEFT);
  //lv_label_set_text(ui_Config_Time, "00:00");
  lv_label_set_text_fmt(ui_Config_Time, "%02i:%02i", pinetime.rtctime.hours(), pinetime.rtctime.minutes());
  lv_obj_set_style_text_font(ui_Config_Time, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_ConfigBatt = lv_label_create(ui_Config_Panel);
  lv_obj_set_width(ui_ConfigBatt, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_ConfigBatt, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_ConfigBatt, -10);
  lv_obj_set_y(ui_ConfigBatt, -10);
  lv_obj_set_align(ui_ConfigBatt, LV_ALIGN_BOTTOM_RIGHT);
  //lv_label_set_text(ui_ConfigBatt, "100%");
  if (pinetime.battIsCharging()) {
    lv_label_set_text(ui_ConfigBatt, "Chr.");
  } else {
    lv_label_set_text_fmt(ui_ConfigBatt, "%i%%", pinetime.mvToPercent(pinetime.readVBAT()));
  }

  lv_obj_set_style_text_font(ui_ConfigBatt, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  //lv_obj_add_event_cb(ui_Config_Button3, ui_event_Config_Button3, LV_EVENT_ALL, NULL);
  //lv_obj_add_event_cb(ui_Config_Button4, ui_event_Config_Button4, LV_EVENT_ALL, NULL);
  //lv_obj_add_event_cb(ui_Config_Button5, ui_event_Config_Button5, LV_EVENT_ALL, NULL);
  //lv_obj_add_event_cb(ui_Config, ui_event_Config, LV_EVENT_ALL, NULL);

  return ui_Config;
}
