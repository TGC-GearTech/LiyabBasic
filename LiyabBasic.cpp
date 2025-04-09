#include "Arduino.h"
#include "LiyabBasic.h"

// Initialization function
void Liyab_Init() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);  // Buzzer pin

  pinMode(9, OUTPUT);  // Motor 1 PWM pin
  pinMode(8, OUTPUT);  // Motor 1 Direction pin 1
  pinMode(7, OUTPUT);  // Motor 1 Direction pin 2
  pinMode(10, OUTPUT); // Motor 2 PWM pin
  pinMode(11, OUTPUT); // Motor 2 Direction pin 1
  pinMode(12, OUTPUT); // Motor 2 Direction pin 2

  // Play a sound on the buzzer
  tone(2, 1250, 350);
  tone(2, 1250, 350);
}

// Function to wait until a button is pressed
void OK() {
  pinMode(13, INPUT_PULLUP);  // Pin 13 set to input with pull-up resistor
  while (digitalRead(13) == 0) {
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
  }
}

// Motor control function
void motor(uint8_t pin, int speed) {
  if (pin == 1) {  // Motor 1 control
    if (speed > 0) {
      int spd = map(speed, 0, 100, 0, 255);
      analogWrite(9, spd);  // Set speed
      digitalWrite(8, HIGH); // Forward direction
      digitalWrite(7, LOW);
    }

    if (speed < 0) {
      int spd = map(speed, 0, -100, 0, 255);
      analogWrite(9, spd);  // Set speed
      digitalWrite(8, LOW);  // Reverse direction
      digitalWrite(7, HIGH);
    }
  }

  if (pin == 2) {  // Motor 2 control
    if (speed > 0) {
      int spd = map(speed, 0, 100, 0, 255);
      analogWrite(10, spd);  // Set speed
      digitalWrite(11, HIGH); // Forward direction
      digitalWrite(12, LOW);
    }

    if (speed < 0) {
      int spd = map(speed, 0, -100, 0, 255);
      analogWrite(10, spd);  // Set speed
      digitalWrite(11, LOW);  // Reverse direction
      digitalWrite(12, HIGH);
    }
  }
}

// Stop both motors
void motor_stop() {
  analogWrite(9, 0);  // Stop Motor 1
  analogWrite(10, 0); // Stop Motor 2
  digitalWrite(8, LOW); // Set Motor 1 to neutral
  digitalWrite(7, LOW);
  digitalWrite(11, LOW); // Set Motor 2 to neutral
  digitalWrite(12, LOW);
}
