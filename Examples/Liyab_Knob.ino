/* Liyab Basic Microcontroller - Knob Calibration */

#include <LiyabBasic.h>

void setup() {
  Liyab_Init();
  OK();
}

void loop() {
  int value = analogRead(knob);
  Serial.println(value);
}
