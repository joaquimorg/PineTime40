#ifndef _PINETIME_UIEVENTS_H
#define _PINETIME_UIEVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

extern void _quick_setings(lv_event_t * e);
extern void _set_bl_value(lv_event_t * e);
extern void _set_backlight(lv_event_t * e);
extern void _charging_load(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif