#ifndef SMARTWATCH_UI_H
#define SMARTWATCH_UI_H

#include "PineTime.h"
#include <stdlib.h>
#include "ui.h"
#include "ui_events.h"

void smartwatch_ui_init(void);

void update_notification(void);
void update_clock(void);

#endif //SMARTWATCH_UI_H
