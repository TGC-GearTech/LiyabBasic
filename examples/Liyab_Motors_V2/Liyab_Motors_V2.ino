/* Liyab Basic Microcontroller - Motor Control */

#include <LiyabBasic.h>

void setup() {
  Liyab_Init();
  OK();
}

void loop() {
  forward(50, 50);
  delay(1000);

  backward(50, 50);
  delay(1000);

  spin_left(50, 50);
  delay(1000);

  spin_right(50, 50);
  delay(1000);

  turn_right(50);
  delay(1000);

  turn_left(50);
  delay(1000);

  motor_stop();
  delay(1000);
}
