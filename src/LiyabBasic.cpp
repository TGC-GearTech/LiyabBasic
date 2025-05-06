#include "Arduino.h"
#include "LiyabBasic.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "Wire.h"
#include "SPI.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

static const unsigned char PROGMEM logo1_bmp[] =
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFC, 0x40, 0x02, 0x4E, 0x4A, 0x51, 0x52,
  0x51, 0x62, 0x51, 0x52, 0x4E, 0x4A, 0x40, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00
};

// Initialization function
void Liyab_Init() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);  // Buzzer pin

  pinMode(9, OUTPUT);  
  pinMode(8, OUTPUT);  
  pinMode(7, OUTPUT);  
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT); 

  // Play a sound on the buzzer
  tone(2, 1250, 350);
  tone(2, 1250, 350);
  
  if(!oled.begin(SSD1306_RIGHT_HORIZONTAL_SCROLL, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 3);
  oled.println(F("LIYAB-01"));
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 25);
  oled.println(F("Press    to Start"));
  oled.drawBitmap(33, 18,logo1_bmp, 16, 16, 1);
  oled.display();
}

// Function to wait until a button is pressed
void OK() {
  pinMode(13, INPUT_PULLUP);  
  while (digitalRead(13) == 0) {
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
    oled.clearDisplay();
    oled.display();
  }
}

void 

// Motor control function
void motor(uint8_t pin, int speed) {
  if (pin == 1) {  
    if (speed > 0) {
      int spd = map(speed, 0, 100, 0, 255);
      analogWrite(9, spd);  
      digitalWrite(8, HIGH); 
      digitalWrite(7, LOW);
    }

    if (speed < 0) {
      int spd = map(speed, 0, -100, 0, 255);
      analogWrite(9, spd);  
      digitalWrite(8, LOW);  
      digitalWrite(7, HIGH);
    }

    if (speed == 0) {
      analogWrite(9, 0);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
    }
  }

  if (pin == 2) {  // Motor 2 control
    if (speed > 0) {
      int spd = map(speed, 0, 100, 0, 255);
      analogWrite(10, spd);  
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
    }

    if (speed < 0) {
      int spd = map(speed, 0, -100, 0, 255);
      analogWrite(10, spd);  
      digitalWrite(11, LOW);  
      digitalWrite(12, HIGH);
    }

    if (speed == 0) {
      analogWrite(10, 0);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
    }
  }
}

void forward(int speedL, int speedR)
{
  int spdL = map(speedL, 0, 100, 0, 255);
  int spdR = map(speedR, 0, 100, 0, 255);
  analogWrite(9, spdL);  
  analogWrite(10, spdR); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH); 
  digitalWrite(12, LOW);
}

void backward(int speedL, int speedR)
{
  int spdL = map(speedL, 0, 100, 0, 255);
  int spdR = map(speedR, 0, 100, 0, 255);
  analogWrite(9, spdL);  
  analogWrite(10, spdR); 
  digitalWrite(8, LOW); 
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW); 
  digitalWrite(12, HIGH);
}

void spin_right(int speedL, int speedR)
{
  int spdL = map(speedL, 0, 100, 0, 255);
  int spdR = map(speedR, 0, 100, 0, 255);
  analogWrite(9, spdL);  
  analogWrite(10, spdR); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, LOW);
  digitalWrite(11, LOW); 
  digitalWrite(12, HIGH);
}

void spin_left(int speedL, int speedR)
{
  int spdL = map(speedL, 0, 100, 0, 255);
  int spdR = map(speedR, 0, 100, 0, 255);
  analogWrite(9, spdL);  
  analogWrite(10, spdR); 
  digitalWrite(8, LOW); 
  digitalWrite(7, HIGH);
  digitalWrite(11, HIGH); 
  digitalWrite(12, LOW);
}

void turn_right(int speedR)
{
  int spd = map(speedR, 0, 100, 0, 255);
  analogWrite(9, spd);  
  analogWrite(10, 0); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, LOW);
  digitalWrite(11, LOW); 
  digitalWrite(12, LOW);
}

void turn_left(int speedL)
{
  int spd = map(speedL, 0, 100, 0, 255);
  analogWrite(9, 0);  
  analogWrite(10, spd); 
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH); 
  digitalWrite(12, LOW);
}

// Stop both motors
void motor_stop() {
  analogWrite(9, 0);  
  analogWrite(10, 0); 
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(11, LOW); 
  digitalWrite(12, LOW);
}
