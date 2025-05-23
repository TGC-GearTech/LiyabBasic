/* Liyab Basic Microcontroller Library */
/* Written by GearTech Robots Trading */
#pragma once

#ifndef LiyabBasic_h 
#define LiyabBasic_h 

#include "Arduino.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "Wire.h"
#include "SPI.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
extern Adafruit_SSD1306 oled;


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
