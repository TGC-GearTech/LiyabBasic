/* Liyab Basic Microcontroller - Motor Control */

#include <LiyabBasic.h>

void setup() {
  Liyab_Init();
  OK();
}

void loop() {
motor(1, 50);
motor(2, 50);
delay(1000);

motor(1, -50);
motor(2, -50);
delay(1000);

motor(1, 50);
motor(2, -50);
delay(1000);

motor(1, -50);
motor(2, 50);
delay(1000);

motor(1, 0);
motor(2, 0);
delay(1000);
}
