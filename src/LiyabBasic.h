/* Liyab Basic Microcontroller Library */
/* Written by GearTech Robots Trading */

#ifndef LiyabBasic_h 
#define LiyabBasic_h 

#include "Arduino.h"

// Function prototypes
void Liyab_Init();
void OK();
void motor(uint8_t pin, int speed);
void forward(int speedL, int speedR);
void backward(int speedL, int speedR);
void spin_left(int speedL, int speedR);
void spin_right(int speedL, int speedR);
void turn_right(int speed);
void turn_left(int speed);
void motor_stop();

#endif 
