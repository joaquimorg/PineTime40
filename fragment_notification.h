#ifndef FRAG_NOTIFICATION_H
#define FRAG_NOTIFICATION_H

#include "PineTime.h"
#include "notification.h"

static void notification_fragment_ctor(lv_fragment_t *self, void *args);

static lv_obj_t *notification_fragment_create_obj(lv_fragment_t *self, lv_obj_t *parent);

typedef struct notification_fragment_t {
  lv_fragment_t base;
  Notification *notification;
} notification_fragment_t;

static const lv_fragment_class_t notification_cls = {
  .constructor_cb = notification_fragment_ctor,
  .create_obj_cb = notification_fragment_create_obj,
  .instance_size = sizeof(struct notification_fragment_t)
};

static void notification_fragment_ctor(lv_fragment_t *self, void *args) {
  //LV_UNUSED(args);
  ((notification_fragment_t *)self)->notification = (Notification *)args;
}

static lv_obj_t *notification_fragment_create_obj(lv_fragment_t *self, lv_obj_t *parent) {

  notification_fragment_t *fragment = (notification_fragment_t *)self;

  lv_obj_t *ui_Notification_Panel = lv_obj_create(parent);
  lv_obj_set_width(ui_Notification_Panel, lv_pct(100));
  lv_obj_set_height(ui_Notification_Panel, lv_pct(100));
  lv_obj_set_align(ui_Notification_Panel, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_Notification_Panel, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(ui_Notification_Panel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER,
                        LV_FLEX_ALIGN_SPACE_EVENLY);
  lv_obj_clear_flag(ui_Notification_Panel, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Notification_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Notification_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Notification_Panel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Notification_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Notification_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Notification_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Notification_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_IconPanel = lv_obj_create(ui_Notification_Panel);
  lv_obj_set_height(ui_IconPanel, 26);
  lv_obj_set_width(ui_IconPanel, lv_pct(100));
  lv_obj_set_align(ui_IconPanel, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_IconPanel, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_IconPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_IconPanel, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_IconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_IconPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_IconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_IconPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_IconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_IconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_IconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_IconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_NotificationIcon = lv_img_create(ui_IconPanel);
  lv_img_set_src(ui_NotificationIcon, &ui_img_message_png);
  lv_obj_set_width(ui_NotificationIcon, LV_SIZE_CONTENT);   /// 22
  lv_obj_set_height(ui_NotificationIcon, LV_SIZE_CONTENT);  /// 22
  lv_obj_set_x(ui_NotificationIcon, 0);
  lv_obj_set_y(ui_NotificationIcon, 10);
  lv_obj_set_align(ui_NotificationIcon, LV_ALIGN_TOP_MID);
  lv_obj_add_flag(ui_NotificationIcon, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_NotificationIcon, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  lv_obj_t *ui_Type = lv_label_create(ui_IconPanel);
  lv_obj_set_width(ui_Type, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Type, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_Type, LV_ALIGN_CENTER);
  lv_label_set_text_fmt(ui_Type, "%s", notification_type(fragment->notification->type));
  lv_obj_set_style_text_font(ui_Type, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_PanelMessage = lv_obj_create(ui_Notification_Panel);
  lv_obj_set_width(ui_PanelMessage, lv_pct(100));
  lv_obj_set_flex_grow(ui_PanelMessage, 1);
  lv_obj_set_align(ui_PanelMessage, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_PanelMessage, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(ui_PanelMessage, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
  lv_obj_set_style_radius(ui_PanelMessage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_PanelMessage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_PanelMessage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_PanelMessage, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_PanelMessage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_PanelMessage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_PanelMessage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_PanelMessage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_NotTitle = lv_label_create(ui_PanelMessage);
  lv_obj_set_width(ui_NotTitle, lv_pct(100));
  lv_obj_set_height(ui_NotTitle, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_NotTitle, LV_ALIGN_CENTER);
  lv_label_set_text(ui_NotTitle, fragment->notification->subject);
  lv_obj_set_style_text_font(ui_NotTitle, &ui_font_OpenSans22Bold, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_NotBody = lv_label_create(ui_PanelMessage);
  lv_obj_set_width(ui_NotBody, lv_pct(100));
  lv_obj_set_height(ui_NotBody, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_NotBody, LV_ALIGN_CENTER);
  lv_label_set_text(ui_NotBody, fragment->notification->message);
  lv_obj_set_style_text_font(ui_NotBody, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_PanelFooter = lv_obj_create(ui_Notification_Panel);
  lv_obj_set_height(ui_PanelFooter, 26);
  lv_obj_set_width(ui_PanelFooter, lv_pct(100));
  lv_obj_set_align(ui_PanelFooter, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_PanelFooter, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_PanelFooter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_PanelFooter, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_PanelFooter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_PanelFooter, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_PanelFooter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_PanelFooter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_PanelFooter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_PanelFooter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_NotificationTime = lv_label_create(ui_PanelFooter);
  lv_obj_set_width(ui_NotificationTime, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_NotificationTime, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_NotificationTime, LV_ALIGN_LEFT_MID);
  lv_label_set_text_fmt(ui_NotificationTime, "%02i:%02i", fragment->notification->hour, fragment->notification->minute);

  uint8_t time_past = pinetime.rtctime.diff_minutes(fragment->notification->timestamp);
  if (time_past > 30) {
    lv_label_set_text_fmt(ui_NotificationTime, "%02i:%02i", fragment->notification->hour, fragment->notification->minute);
  } else if (time_past < 1) {
    lv_label_set_text_static(ui_NotificationTime, "Just now");
  } else {
    lv_label_set_text_fmt(ui_NotificationTime, "%i min", time_past);
  }

  return ui_Notification_Panel;
}

#endif  // FRAG_NOTIFICATION_H