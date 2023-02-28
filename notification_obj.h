#ifndef NOTIFICATION_OBJ_H
#define NOTIFICATION_OBJ_H

#include "PineTime.h"
#include "notification.h"

lv_obj_t *notification_create_obj(lv_obj_t *parent, Notification *notification) {  

  lv_obj_t *cui_Notification;
  cui_Notification = lv_obj_create(parent);
  lv_obj_set_height(cui_Notification, 108);
  lv_obj_set_width(cui_Notification, lv_pct(100));
  lv_obj_set_align(cui_Notification, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(cui_Notification, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(cui_Notification, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
  //lv_obj_add_flag(cui_Notification, LV_OBJ_FLAG_EVENT_BUBBLE);                                                                                                                                                                       /// Flags
  //lv_obj_clear_flag(cui_Notification, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_scrollbar_mode(cui_Notification, LV_SCROLLBAR_MODE_OFF);
  lv_obj_set_style_bg_color(cui_Notification, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(cui_Notification, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(cui_Notification, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(cui_Notification, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(cui_Notification, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(cui_Notification, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(cui_Notification, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *cui_PanelType;
  cui_PanelType = lv_obj_create(cui_Notification);
  lv_obj_set_height(cui_PanelType, 26);
  lv_obj_set_width(cui_PanelType, lv_pct(100));
  lv_obj_set_align(cui_PanelType, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(cui_PanelType, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(cui_PanelType, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(cui_PanelType, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_radius(cui_PanelType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(cui_PanelType, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(cui_PanelType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(cui_PanelType, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(cui_PanelType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(cui_PanelType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(cui_PanelType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(cui_PanelType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *cui_TypeIcon;
  cui_TypeIcon = lv_img_create(cui_PanelType);
  lv_img_set_src(cui_TypeIcon, &ui_img_message_png);
  lv_obj_set_width(cui_TypeIcon, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(cui_TypeIcon, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(cui_TypeIcon, LV_ALIGN_CENTER);
  lv_obj_add_flag(cui_TypeIcon, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(cui_TypeIcon, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  lv_obj_t *cui_NotifType;
  cui_NotifType = lv_label_create(cui_PanelType);
  lv_obj_set_width(cui_NotifType, lv_pct(100));
  lv_obj_set_height(cui_NotifType, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(cui_NotifType, LV_ALIGN_CENTER);
  //lv_label_set_text(cui_NotifType, "Skype");
  lv_label_set_text_fmt(cui_NotifType, "%s", notification_type(notification->type));
  lv_obj_clear_flag(cui_NotifType, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_text_color(cui_NotifType, lv_color_hex(0xC8C8C8), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(cui_NotifType, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(cui_NotifType, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *cui_NotifTitle;
  cui_NotifTitle = lv_label_create(cui_Notification);
  lv_obj_set_width(cui_NotifTitle, lv_pct(100));
  lv_obj_set_height(cui_NotifTitle, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(cui_NotifTitle, LV_ALIGN_CENTER);
  lv_label_set_text_fmt(cui_NotifTitle, "%s",notification->subject);
  lv_obj_clear_flag(cui_NotifTitle, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
  lv_obj_set_style_text_color(cui_NotifTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(cui_NotifTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(cui_NotifTitle, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *cui_NotifDate;
  cui_NotifDate = lv_label_create(cui_Notification);
  lv_obj_set_width(cui_NotifDate, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(cui_NotifDate, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(cui_NotifDate, LV_ALIGN_CENTER);
  //lv_label_set_text(cui_NotifDate, "13:48");
  lv_label_set_text_fmt(cui_NotifDate, "%02i:%02i", notification->hour, notification->minute);
  lv_obj_set_style_text_color(cui_NotifDate, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(cui_NotifDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(cui_NotifDate, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  return cui_Notification;
}

#endif  //NOTIFICATION_OBJ_H