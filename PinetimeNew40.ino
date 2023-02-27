#include "PineTime.h"
#include <stdlib.h>

#include "smartwatch_ui.h"

typedef volatile uint32_t REG32;
#define pREG32 (REG32 *)

#define DEVICE_ID_HIGH (*(pREG32(0x10000060)))
#define DEVICE_ID_LOW (*(pREG32(0x10000064)))

// ---------------------------------------------------------------------------------------------------------------------------------

void setup() {

  Serial.begin(115200);  // start serial for output
  while (!Serial) delay(100);

  Serial.println("");
  Serial.println("--------------------------------------");

  // Unique Device ID
  Serial.print("# Device ID  : ");
  Serial.print(DEVICE_ID_HIGH, HEX);
  Serial.println(DEVICE_ID_LOW, HEX);

  // MCU Variant;
  Serial.printf("# MCU Variant: nRF%X 0x%08X\n", NRF_FICR->INFO.PART, NRF_FICR->INFO.VARIANT);
  Serial.printf("# Memory     : Flash = %d KB, RAM = %d KB\n", NRF_FICR->INFO.FLASH, NRF_FICR->INFO.RAM);
  Serial.println("");

  // Init PineTime Hardware
  pinetime.begin();

  Serial.println("> UI init");

  smartwatch_ui_init();

  pinetime.updateScreen(update_clock);
  pinetime.updateNotification(update_notification);
}

// ---------------------------------------------------------------------------------------------------------------------------------

void loop() {
  pinetime.loop();
  delay(5);
}