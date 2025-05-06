#include <LiyabBasic.h>

void setup() {
  Liyab_Init();
  OK();

}

void loop() {
  Serial.print("A0: ");
  Serial.print(analogRead(A0));
  Serial.print(" | ");
  Serial.print("A1: ");
  Serial.print(analogRead(A1));
  Serial.print(" | ");
  Serial.print("A2: ");
  Serial.print(analogRead(A2));
  Serial.print(" | ");
  Serial.print("A3: ");
  Serial.print(analogRead(A3));
  Serial.print(" | ");
  Serial.print("A6: ");
  Serial.print(analogRead(A6));
  Serial.print(" | ");
  Serial.print("D0: ");
  Serial.print(digitalRead(0));
  Serial.print(" | ");
  Serial.print("D1: ");
  Serial.print(digitalRead(1));
  Serial.print(" | ");
  Serial.print("D3: ");
  Serial.print(digitalRead(3));
  Serial.print(" | ");
  Serial.print("D4: ");
  Serial.print(digitalRead(4));
  Serial.print(" | ");
  Serial.print("D5: ");
  Serial.print(digitalRead(5));
  Serial.print(" | ");
  Serial.print("D6: ");
  Serial.println(digitalRead(6));

}
