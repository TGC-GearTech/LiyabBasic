#include "Arduino.h"
#include "LiyabBasic.h"

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
}

// Function to wait until a button is pressed
void OK() {
  pinMode(13, INPUT_PULLUP);  
  while (digitalRead(13) == 0) {
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
  }
}

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

// Stop both motors
void motor_stop() {
  analogWrite(9, 0);  
  analogWrite(10, 0); 
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(11, LOW); 
  digitalWrite(12, LOW);
}
