#include "PineTime.h"
#include <stdlib.h>

#include "ui.h"
#include "ui_events.h"

#include "smartwatch_ui.h"
#include "notification_obj.h"

#include "fragment_notification.h"

lv_obj_t *root = NULL;
lv_fragment_manager_t *f_manager = NULL;

lv_obj_t *tv;
lv_obj_t *tile1;
lv_obj_t *tile2;
lv_obj_t *tile3;
lv_obj_t *tile4;

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
  lv_obj_t * o_not = lv_event_get_target(e);

  int notPos = l_not.Find(o_not);
  if ( notPos != -1 ) {
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

  f_manager = lv_fragment_manager_create(NULL);
  lv_obj_add_event_cb(root, ui_event_root, LV_EVENT_ALL, f_manager);

  // animation  ???
  lv_timer_t *timeranim = lv_timer_create(timerAnim, 200, NULL);
}
