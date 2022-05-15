#include "lvgl/lvgl.h"

void test_lvgl(void) {
  lv_obj_t *scr1 = lv_obj_create(NULL);
  lv_scr_load(scr1);

  lv_obj_t *parent = lv_obj_create(NULL);
  lv_scr_load(parent);
  // lv_scr_load_anim(parent, LV_SCR_LOAD_ANIM_OVER_LEFT, 3000, 3000, false);
  lv_obj_set_size(parent, 300, 200);
  // lv_obj_set_pos(parent, 50, 50);

  lv_obj_t *obj1 = lv_obj_create(parent);
  lv_obj_align(obj1, LV_ALIGN_CENTER, 0, 0);

  static lv_style_t style;
  lv_style_init(&style);
  lv_style_set_width(&style, 100);

  lv_obj_t *btn = lv_btn_create(parent);
  lv_obj_add_style(btn, &style, LV_PART_MAIN);
}

void test_lvgl_1(void) {
  const lv_obj_t *parent = lv_scr_act();
  lv_obj_t *btn1 = lv_btn_create(parent);
  // lv_obj_t *btn2 = lv_btn_create(parent);
  // lv_obj_t *btn3 = lv_btn_create(parent);

  static lv_style_t style_normal;
  lv_style_init(&style_normal);
  lv_style_set_y(&style_normal, 100);

  static lv_style_t style_pressed;
  lv_style_init(&style_pressed);
  // lv_style_set_translate_y(&style_pressed, -20);
  lv_style_set_transform_width(&style_pressed, 10);
  lv_style_set_transform_height(&style_pressed, 10);

  static lv_style_t style_max_width;
  lv_style_init(&style_max_width);
  lv_style_set_max_width(&style_max_width, lv_pct(50));

  /*Only its pointer is saved so must static, global or dynamically allocated */
  static const lv_style_prop_t trans_props[] = {
      LV_STYLE_BG_OPA, LV_STYLE_BG_COLOR, 0, /*End marker*/
  };
  static lv_style_transition_dsc_t trans1;
  lv_style_transition_dsc_init(&trans1, trans_props, lv_anim_path_ease_in,
                               10000, 10000, NULL);
  lv_style_set_transition(&style_pressed, &trans1);

  lv_obj_add_style(btn1, &style_normal, LV_STATE_DEFAULT);
  lv_obj_add_style(btn1, &style_pressed, LV_STATE_PRESSED);

  lv_obj_set_width(btn1, lv_pct(100));
  lv_obj_add_style(btn1, &style_max_width,
                   LV_STATE_DEFAULT); // Limit the  height to 200 px

  // lv_obj_add_style(btn2, &style_normal, LV_STATE_DEFAULT);
  // lv_obj_add_style(btn2, &style_pressed, LV_STATE_PRESSED);

  // lv_obj_add_style(btn3, &style_normal, LV_STATE_DEFAULT);
  // lv_obj_add_style(btn3, &style_pressed, LV_STATE_PRESSED);

  // lv_theme_t * th = lv_theme_default_init(display,  /*Use the DPI, size, etc
  // from this display*/
  //                                         LV_COLOR_PALETTE_BLUE,
  //                                         LV_COLOR_PALETTE_CYAN,   /*Primary
  //                                         and secondary palette*/ false,
  //                                         /*Light or dark mode*/
  //                                         &lv_font_montserrat_10,
  //                                         &lv_font_montserrat_14,
  //                                         &lv_font_montserrat_18); /*Small,
  //                                         normal, large fonts*/

  // lv_disp_set_theme(display, th); /*Assign the theme to the display*/
}

void test_lvgl_2(void) {

}