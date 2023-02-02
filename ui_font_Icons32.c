/*******************************************************************************
 * Size: 38 px
 * Bpp: 2
 * Opts: --bpp 2 --size 38 --font D:\Work\Arduino\PinetimeArduino\assets\Fonts\sysicons.ttf -o D:\Work\Arduino\PinetimeArduino\assets\Fonts\ui_font_Icons32.c --format lvgl -r 0xe900-0xe910 --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_ICONS32
#define UI_FONT_ICONS32 1
#endif

#if UI_FONT_ICONS32

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E900 "" */
    0x0, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x40, 0x0, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x43, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xfe,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf8, 0x3f, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xe0, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf7, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf3, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfe, 0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf8, 0x3f, 0xfe, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xd0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E901 "" */
    0x0, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x40, 0x0, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x43, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xfe,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf8, 0x3f, 0xf0, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x50, 0x3f, 0xe0, 0xff, 0xc3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff,
    0xf7, 0xff, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0xf, 0xff, 0xff, 0xf0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f,
    0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0xff, 0xff, 0xff, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3, 0xff, 0xff, 0xfc,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf,
    0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x3f, 0xff, 0xff, 0xc3, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xf3, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfe, 0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf8, 0x3f, 0xfe, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xd0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E902 "" */
    0x0, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x40, 0x0, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x43, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xfe,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf8, 0x3f, 0xf0, 0x55, 0x55, 0x55,
    0x50, 0x0, 0x0, 0x0, 0x3f, 0xe0, 0xff, 0xc3,
    0xff, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x0, 0xff,
    0xf7, 0xff, 0xf, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff,
    0xfd, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0xff, 0xff, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xd0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xff, 0xf, 0xff, 0xff,
    0xff, 0x40, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x3f, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf4, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc3, 0xff, 0xff,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0xff, 0xf3, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfe, 0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf8, 0x3f, 0xfe, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xd0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E903 "" */
    0x0, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x40, 0x0, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x43, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xfe,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf8, 0x3f, 0xf0, 0x55, 0x54, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xe0, 0xff, 0xc3,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf7, 0xff, 0xf, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xc3, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xff, 0xf, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x3f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc3, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf3, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfe, 0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf8, 0x3f, 0xfe, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xd0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E904 "" */
    0x0, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x40, 0x0, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x43, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xfe,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf8, 0x3f, 0xf0, 0x55, 0x55, 0x55,
    0x55, 0x54, 0x0, 0x0, 0x3f, 0xe0, 0xff, 0xc3,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0, 0xff,
    0xf7, 0xff, 0xf, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0xff, 0xff, 0xff, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc3, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0xff, 0xf3, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfe, 0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf8, 0x3f, 0xfe, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xd0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E905 "" */
    0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff,
    0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0xb, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x40, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfd, 0x0, 0x0, 0x3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0,
    0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfd, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0xb, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xaa, 0xaa, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E906 "" */
    0x1e, 0x0, 0x0, 0x0, 0x0, 0x1, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0x40, 0x0, 0x0, 0x0, 0xbf, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf8, 0x0,
    0x0, 0x0, 0x2f, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x7f, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xfd,
    0x0, 0x1, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0xd0, 0x2, 0xff, 0xff,
    0xff, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xfe, 0x3, 0xff, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xbf, 0xf2, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xc, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xd0, 0x3, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xfd, 0x0, 0x2f, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0xe0, 0x1, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0x0, 0x1f,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xff, 0xf4, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0x80,
    0xb, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xf8, 0x0, 0x7f, 0xff, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0xb, 0xff, 0xff, 0xff,
    0xc0, 0x3, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x2f, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0x2, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x1f,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xf4, 0x0, 0xff, 0xf4, 0x0, 0x0,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40,
    0xb, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2a, 0xaa, 0xa4, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xfd,
    0x0, 0x0, 0x2, 0xff, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xff, 0xff, 0x0, 0x0, 0x0, 0x1f,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0x40, 0x0, 0x0, 0x0, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xff, 0x40, 0x0, 0x0, 0x0,
    0xb, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E907 "" */
    0x0, 0x0, 0x64, 0x0, 0x0, 0x6, 0x80, 0x0,
    0x0, 0x0, 0x2f, 0xe0, 0x0, 0x1, 0xff, 0x0,
    0x0, 0x0, 0x3, 0xff, 0x0, 0x0, 0x2f, 0xf0,
    0x0, 0x0, 0x0, 0x3f, 0xf0, 0x0, 0x2, 0xff,
    0x0, 0x0, 0x0, 0x3, 0xff, 0x0, 0x0, 0x2f,
    0xf0, 0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xd0, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x8f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0xfd, 0x3, 0xff, 0x80, 0x7f, 0xf4,
    0xf, 0xfd, 0xff, 0xc0, 0x2f, 0xf4, 0x3, 0xff,
    0x0, 0xbf, 0xdf, 0xfc, 0x2, 0xff, 0x40, 0x3f,
    0xf0, 0xb, 0xfd, 0xff, 0xc0, 0x2f, 0xf4, 0x3,
    0xff, 0x0, 0xbf, 0xdf, 0xfc, 0x2, 0xff, 0x40,
    0x3f, 0xf0, 0xb, 0xfd, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfc,
    0x2, 0xff, 0x40, 0x3f, 0xf0, 0xb, 0xfd, 0xff,
    0xc0, 0x2f, 0xf4, 0x3, 0xff, 0x0, 0xbf, 0xdf,
    0xfc, 0x2, 0xff, 0x40, 0x3f, 0xf0, 0xb, 0xfd,
    0xff, 0xc0, 0x2f, 0xf4, 0x3, 0xff, 0x0, 0xbf,
    0xdf, 0xfe, 0xab, 0xff, 0xea, 0xff, 0xfa, 0xaf,
    0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+E908 "" */
    0x0, 0x0, 0x0, 0x1, 0x6a, 0x94, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xff, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x2,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xf,
    0xff, 0xff, 0xff, 0xd0, 0x7f, 0xff, 0xff, 0xff,
    0x1, 0xff, 0xff, 0xff, 0xfc, 0x3, 0xff, 0xff,
    0xff, 0xf4, 0x2f, 0xff, 0xff, 0xff, 0x80, 0x2f,
    0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xfc,
    0x3, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff,
    0xff, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x0,
    0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x90, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xbf, 0xff, 0xff, 0xff, 0xf0, 0x2f, 0xff,
    0xff, 0xff, 0xeb, 0xff, 0xff, 0xff, 0xff, 0x2,
    0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff,
    0xf0, 0x2f, 0xff, 0xff, 0xff, 0xd3, 0xff, 0xff,
    0xff, 0xd0, 0x0, 0x7f, 0xff, 0xff, 0xfc, 0x2f,
    0xff, 0xff, 0xf4, 0x0, 0x1, 0xff, 0xff, 0xff,
    0x80, 0xff, 0xff, 0xff, 0x40, 0x0, 0x1f, 0xff,
    0xff, 0xf0, 0xb, 0xff, 0xff, 0xfc, 0x0, 0x3,
    0xff, 0xff, 0xfe, 0x0, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x0, 0xb,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0x0, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0xf9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x55, 0x50, 0x0,
    0x0, 0x0, 0x0,

    /* U+E909 "" */
    0x0, 0x0, 0x0, 0x6, 0xbf, 0xe9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1b, 0xff, 0xff, 0xfe,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0x40, 0x0, 0x0, 0x0, 0xb, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0,
    0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0xf, 0xff, 0xff, 0xff, 0x5f,
    0xff, 0xff, 0xff, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xd0, 0x7f, 0xff, 0xff, 0xf8, 0x0, 0x7f, 0xff,
    0xff, 0xfc, 0x3, 0xff, 0xff, 0xff, 0xd0, 0xf,
    0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 0xff,
    0x1, 0xff, 0xff, 0xff, 0xfc, 0x3, 0xff, 0xff,
    0xff, 0xf4, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0x3f,
    0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xfc,
    0x3, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff,
    0xff, 0xc0, 0x3f, 0xff, 0xff, 0xff, 0xdb, 0xff,
    0xff, 0xff, 0xfc, 0x3, 0xff, 0xff, 0xff, 0xfe,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0xbf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xd0, 0x1, 0xff, 0xff,
    0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3,
    0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x40, 0xf, 0xff, 0xfd, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0xff, 0xff, 0xc3, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x7f, 0xff, 0xfc, 0x2f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x0, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x0, 0x7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x0,
    0x0, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xd0, 0x0, 0x0, 0x1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xbf, 0xff, 0xe4, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0,

    /* U+E90A "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0xff, 0xfe,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40,
    0x0, 0x0, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x80, 0x0, 0x2, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x2f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x3, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0xbf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0x0, 0xb, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x7f, 0xff, 0xf7,
    0xff, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x3, 0xff,
    0xfe, 0x0, 0x5a, 0xaa, 0x50, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0x90, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E90B "" */
    0x0, 0x0, 0x55, 0x40, 0x0, 0x0, 0x15, 0x50,
    0x0, 0x0, 0x0, 0xbf, 0xff, 0x90, 0x0, 0x6f,
    0xff, 0xe0, 0x0, 0x0, 0xbf, 0xff, 0xff, 0x80,
    0x2f, 0xff, 0xff, 0xe0, 0x0, 0x2f, 0xff, 0xff,
    0xff, 0xf, 0xff, 0xff, 0xff, 0x80, 0xb, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf4, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0xbf, 0xff, 0xff, 0x87,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff,
    0xf0, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfd, 0x0, 0xff, 0xfd, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0, 0xb, 0xff, 0x2, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x3f, 0xe0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x2,
    0xfc, 0x0, 0xbf, 0xff, 0xff, 0xbf, 0xff, 0xf0,
    0x0, 0x1f, 0x80, 0x3, 0xff, 0xff, 0xe0, 0x0,
    0x0, 0x3, 0x40, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x38, 0x6, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x38,
    0x0, 0x0, 0x0, 0x1, 0x55, 0x5b, 0xfe, 0x0,
    0x7, 0xf5, 0x55, 0x54, 0x0, 0x2f, 0xff, 0xff,
    0xf0, 0x0, 0xff, 0xff, 0xff, 0x80, 0x0, 0xbf,
    0xff, 0xff, 0x40, 0x1f, 0xff, 0xff, 0xe0, 0x0,
    0x2, 0xff, 0xff, 0xfc, 0x3, 0xff, 0xff, 0xf8,
    0x0, 0x0, 0x7, 0xff, 0xff, 0xd0, 0x7f, 0xff,
    0xfd, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xaf,
    0xff, 0xff, 0x40, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xb, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0x80, 0x0, 0x0,
    0x0, 0x0,

    /* U+E90C "" */
    0x0, 0x0, 0x5, 0xa9, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x0, 0xbf,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xf8, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0xf, 0xff, 0xe4, 0x3f, 0xff, 0xf8,
    0x0, 0xff, 0xf8, 0x0, 0xbf, 0xff, 0xf4, 0x7,
    0xff, 0x40, 0x17, 0xff, 0xff, 0xf0, 0x3f, 0xf8,
    0xb, 0xff, 0xff, 0xff, 0xd0, 0xff, 0xc0, 0xff,
    0xff, 0xff, 0xff, 0x87, 0xfe, 0xf, 0xff, 0xff,
    0xff, 0xff, 0x2f, 0xf0, 0x7f, 0xff, 0xff, 0xff,
    0xfc, 0xff, 0xc2, 0xff, 0xff, 0xff, 0xff, 0xf7,
    0xff, 0xb, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xfe,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0x2f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xb,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0x2f, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xd0,
    0x0, 0x0, 0x7f, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0xbf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x2, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0xb, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E90D "" */
    0x0, 0x0, 0x0, 0x1b, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xf0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xbf, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x40, 0x0, 0x0, 0x0, 0x1, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xd0, 0x0,
    0x0, 0xbf, 0xff, 0xff, 0xf4, 0x0, 0x2, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x7, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0xf, 0xff, 0x7f, 0xff, 0xff, 0x0,
    0x1f, 0xfc, 0x3f, 0xff, 0xff, 0x40, 0x2f, 0xf4,
    0x7f, 0xff, 0xff, 0xd0, 0x2f, 0xf0, 0xbf, 0xff,
    0xff, 0xf8, 0xf, 0xd0, 0xff, 0xfd, 0x7f, 0xfe,
    0x1, 0x0, 0xff, 0xfc, 0x3f, 0xfe, 0x0, 0x0,
    0xff, 0xfc, 0xb, 0xfd, 0x0, 0x0, 0xbf, 0xf8,
    0x0, 0x64, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0x0, 0x0, 0x0, 0x1,
    0xb, 0xff, 0xc0, 0x0, 0x0, 0xb, 0x2, 0xff,
    0xf0, 0x0, 0x0, 0xf, 0xc0, 0xbf, 0xf8, 0x0,
    0x0, 0x1f, 0xf0, 0x2f, 0xfc, 0x0, 0x0, 0x3f,
    0xf4, 0xf, 0xfd, 0x0, 0x0, 0xbf, 0xf0, 0x7,
    0xfe, 0x0, 0x2, 0xff, 0xd0, 0x3, 0xff, 0x0,
    0xb, 0xff, 0xc0, 0x3, 0xff, 0x0, 0x2f, 0xff,
    0x0, 0x2, 0xff, 0x40, 0xbf, 0xfc, 0x0, 0x1,
    0xff, 0x80, 0xff, 0xf0, 0x0, 0x0, 0xff, 0x80,
    0xff, 0xc0, 0x0, 0x0, 0xff, 0x80, 0x3f, 0x0,
    0x0, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+E90E "" */
    0x0, 0x5, 0x0, 0x0, 0x0, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0xb,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xfd,
    0x0, 0x0, 0x3f, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf4, 0x0, 0x0, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xd0, 0x0, 0x3,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0x40, 0x0, 0xf, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xfd, 0x0, 0x0, 0x3f, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf4, 0x0, 0x0,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xd0, 0x0, 0x3, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0x40, 0x0, 0xf, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1a, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xa8,
    0x0, 0x0, 0x0, 0x2, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x1, 0xbf, 0xe4,
    0x0, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x80,
    0x7f, 0xff, 0xfd, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0xb, 0xff, 0xff, 0xff, 0x0, 0xb,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xfe, 0xb,
    0xff, 0xff, 0xeb, 0xff, 0x0, 0x3f, 0xff, 0xff,
    0xff, 0xf0, 0x7f, 0xff, 0xfd, 0xf, 0xfd, 0x0,
    0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xc0,
    0xbf, 0xfc, 0x1, 0xff, 0xff, 0xff, 0xfd, 0xf,
    0xff, 0xf8, 0x3, 0xff, 0xf0, 0x3, 0xff, 0xff,
    0xff, 0xf0, 0x7f, 0xff, 0x40, 0x2f, 0xff, 0xe0,
    0x3, 0xff, 0xff, 0xff, 0xc2, 0xff, 0xe0, 0x0,
    0xff, 0xff, 0x80, 0x3, 0xff, 0xff, 0xff, 0xb,
    0xff, 0x0, 0x0, 0xf, 0xfe, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x2f, 0xff, 0xa0, 0x0, 0xbf, 0xf8,
    0x0, 0x2, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xc0,
    0xf, 0xff, 0xe0, 0x0, 0x0, 0x6f, 0xfe, 0x0,
    0xff, 0xfd, 0x1, 0xff, 0xff, 0x40, 0x0, 0x0,
    0x3f, 0xe0, 0x3, 0xff, 0xf0, 0x2f, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0xff, 0x80, 0x7, 0xff, 0x43,
    0xff, 0xff, 0xd0, 0x0, 0x0, 0x3, 0xfe, 0x0,
    0xf, 0xfe, 0x7f, 0xff, 0xff, 0x0, 0x0, 0x0,
    0xf, 0xf8, 0x0, 0xf, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3f, 0xe0, 0x0, 0xf, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0xff, 0x40,
    0x0, 0xb, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x1, 0xfc, 0x0, 0x0, 0x2, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+E90F "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x6a,
    0x94, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6, 0xbf, 0xff, 0xff, 0xe4, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xc3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x40, 0x0, 0x0, 0xf, 0xff,
    0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0,
    0x0, 0x0, 0xf, 0xff, 0xc3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf4, 0x0, 0x0, 0x1f, 0xff,
    0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0xf, 0xff, 0xc3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0xf, 0xff,
    0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x0, 0x0, 0x3, 0xff, 0xc3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0xff,
    0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x5b, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0xff, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0xff, 0xfa, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xe9,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xff,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x54, 0x6, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xd0, 0x0, 0x0, 0xf, 0xfc, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x3f, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0xbf, 0xfc, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0xff, 0xfc, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x0, 0x0,
    0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x7f, 0xfc, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0xb, 0xfc, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0xff, 0xff, 0xfe, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x55, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+E910 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6, 0xff, 0xfe, 0x40, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0xbf,
    0xff, 0xff, 0xff, 0xf4, 0x0, 0x0, 0xbf, 0xff,
    0xcf, 0xff, 0xff, 0x40, 0x0, 0x7f, 0xff, 0xf0,
    0xff, 0xff, 0xf0, 0x0, 0x3f, 0xff, 0xfc, 0xf,
    0xff, 0xfe, 0x0, 0x2f, 0xff, 0xff, 0x0, 0xff,
    0xff, 0xc0, 0xf, 0xff, 0xff, 0xc0, 0xf, 0xff,
    0xf8, 0x7, 0xff, 0xff, 0xf0, 0x0, 0xff, 0xff,
    0x2, 0xff, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xd0,
    0xff, 0xf7, 0xff, 0x3, 0x0, 0xff, 0xf8, 0x3f,
    0xf4, 0x3f, 0xc0, 0xf0, 0xf, 0xff, 0x1f, 0xfc,
    0x3, 0xf0, 0x3f, 0x1, 0xff, 0xc7, 0xff, 0xc0,
    0x3c, 0xf, 0x0, 0xff, 0xf2, 0xff, 0xfc, 0x3,
    0x3, 0x0, 0xff, 0xfc, 0xbf, 0xff, 0xc0, 0x0,
    0x0, 0xff, 0xff, 0x6f, 0xff, 0xfc, 0x0, 0x0,
    0xff, 0xff, 0xdb, 0xff, 0xff, 0xc0, 0x0, 0xff,
    0xff, 0xf6, 0xff, 0xff, 0xfc, 0x0, 0xff, 0xff,
    0xfd, 0xbf, 0xff, 0xff, 0x0, 0x3f, 0xff, 0xff,
    0x6f, 0xff, 0xff, 0x0, 0x3, 0xff, 0xff, 0xdb,
    0xff, 0xff, 0x0, 0x0, 0x3f, 0xff, 0xf6, 0xff,
    0xff, 0x0, 0x1, 0x3, 0xff, 0xfd, 0xbf, 0xff,
    0x0, 0xc0, 0xd0, 0x3f, 0xff, 0x1f, 0xff, 0x0,
    0xf0, 0x3d, 0x3, 0xff, 0xc7, 0xff, 0x0, 0xfc,
    0xf, 0xc0, 0x7f, 0xf0, 0xff, 0xd0, 0xff, 0x3,
    0xc0, 0x3f, 0xfc, 0x3f, 0xfe, 0xff, 0xc0, 0xc0,
    0x3f, 0xfe, 0xb, 0xff, 0xff, 0xf0, 0x0, 0x3f,
    0xff, 0x41, 0xff, 0xff, 0xfc, 0x0, 0x3f, 0xff,
    0xc0, 0x3f, 0xff, 0xff, 0x0, 0x3f, 0xff, 0xe0,
    0x7, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xf0, 0x0,
    0xff, 0xff, 0xf0, 0x7f, 0xff, 0xf8, 0x0, 0xf,
    0xff, 0xfc, 0x7f, 0xff, 0xfc, 0x0, 0x1, 0xff,
    0xff, 0x7f, 0xff, 0xfc, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0xbf, 0xff,
    0xff, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x6b, 0xfa,
    0x40, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 684, .box_w = 43, .box_h = 25, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 269, .adv_w = 684, .box_w = 43, .box_h = 25, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 538, .adv_w = 684, .box_w = 43, .box_h = 25, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 807, .adv_w = 684, .box_w = 43, .box_h = 25, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1076, .adv_w = 684, .box_w = 43, .box_h = 25, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1345, .adv_w = 532, .box_w = 35, .box_h = 39, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 1687, .adv_w = 760, .box_w = 49, .box_h = 39, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 2165, .adv_w = 532, .box_w = 34, .box_h = 39, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2497, .adv_w = 608, .box_w = 38, .box_h = 39, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2868, .adv_w = 608, .box_w = 38, .box_h = 39, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 3239, .adv_w = 608, .box_w = 39, .box_h = 35, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 3581, .adv_w = 608, .box_w = 38, .box_h = 33, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3895, .adv_w = 456, .box_w = 27, .box_h = 39, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 4159, .adv_w = 380, .box_w = 24, .box_h = 39, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 4393, .adv_w = 684, .box_w = 43, .box_h = 39, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 4813, .adv_w = 760, .box_w = 48, .box_h = 39, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 5281, .adv_w = 521, .box_w = 29, .box_h = 39, .ofs_x = 2, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 59648, .range_length = 17, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Icons32 = {
#else
lv_font_t ui_font_Icons32 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 39,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_ICONS32*/

