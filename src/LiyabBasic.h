/* Liyab Basic Microcontroller Library */
/* Written by GearTech Robots Trading */

#ifndef LiyabBasic_h 
#define LiyabBasic_h 

#include "Arduino.h"

#define knob analogRead(A2)
#define buzzer 2
// Function prototypes
void Liyab_Init();
void OK();
void motor(uint8_t pin, int speed);
void motor_stop();

#endif 
