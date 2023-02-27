#ifndef FRAG_NOTIFICATION_H
#define FRAG_NOTIFICATION_H


static void notification_fragment_ctor(lv_fragment_t *self, void *args);

static lv_obj_t *notification_fragment_create_obj(lv_fragment_t *self, lv_obj_t *parent);

typedef struct notification_fragment_t {
  lv_fragment_t base;
} notification_fragment_t;

static const lv_fragment_class_t notification_cls = {
  .constructor_cb = notification_fragment_ctor,
  .create_obj_cb = notification_fragment_create_obj,
  .instance_size = sizeof(struct notification_fragment_t)
};

static void notification_fragment_ctor(lv_fragment_t *self, void *args) {
  LV_UNUSED(args);
}

static lv_obj_t *notification_fragment_create_obj(lv_fragment_t *self, lv_obj_t *parent) {

  lv_obj_t *ui_Config_Panel2 = lv_obj_create(parent);
  lv_obj_set_width(ui_Config_Panel2, 240);
  lv_obj_set_height(ui_Config_Panel2, 240);
  lv_obj_set_align(ui_Config_Panel2, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Config_Panel2, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Config_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Config_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Config_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_Config_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Panel7 = lv_obj_create(ui_Config_Panel2);
  lv_obj_set_width(ui_Panel7, 200);
  lv_obj_set_height(ui_Panel7, 190);
  lv_obj_set_x(ui_Panel7, 0);
  lv_obj_set_y(ui_Panel7, 5);
  lv_obj_set_align(ui_Panel7, LV_ALIGN_TOP_MID);
  lv_obj_set_flex_flow(ui_Panel7, LV_FLEX_FLOW_ROW_WRAP);
  lv_obj_set_flex_align(ui_Panel7, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_EVENLY);
  lv_obj_clear_flag(ui_Panel7, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Panel7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_Panel7, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Button3 = lv_btn_create(ui_Panel7);
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

  lv_obj_t *ui_Config_Button6 = lv_btn_create(ui_Panel7);
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

  lv_obj_t *ui_Config_Button4 = lv_btn_create(ui_Panel7);
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

  lv_obj_t *ui_Config_Button5 = lv_btn_create(ui_Panel7);
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

  lv_obj_t *ui_Config_Batt_Icon = lv_label_create(ui_Config_Panel2);
  lv_obj_set_width(ui_Config_Batt_Icon, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Batt_Icon, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Config_Batt_Icon, 27);
  lv_obj_set_y(ui_Config_Batt_Icon, -3);
  lv_obj_set_align(ui_Config_Batt_Icon, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_Config_Batt_Icon, "");
  lv_obj_set_style_text_color(ui_Config_Batt_Icon, lv_color_hex(0x017515), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Config_Batt_Icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Config_Batt_Icon, &ui_font_Icons32, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_Config_Time = lv_label_create(ui_Config_Panel2);
  lv_obj_set_width(ui_Config_Time, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Config_Time, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_Config_Time, 10);
  lv_obj_set_y(ui_Config_Time, -10);
  lv_obj_set_align(ui_Config_Time, LV_ALIGN_BOTTOM_LEFT);
  lv_label_set_text(ui_Config_Time, "00:00");
  lv_obj_set_style_text_font(ui_Config_Time, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_ConfigBatt = lv_label_create(ui_Config_Panel2);
  lv_obj_set_width(ui_ConfigBatt, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_ConfigBatt, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_ConfigBatt, -10);
  lv_obj_set_y(ui_ConfigBatt, -10);
  lv_obj_set_align(ui_ConfigBatt, LV_ALIGN_BOTTOM_RIGHT);
  lv_label_set_text(ui_ConfigBatt, "100%");
  lv_obj_set_style_text_font(ui_ConfigBatt, &ui_font_OpenSans22, LV_PART_MAIN | LV_STATE_DEFAULT);
  return ui_Config_Panel2;
}

#endif // FRAG_NOTIFICATION_H