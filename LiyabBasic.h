/* Liyab Basic Microcontroller Library */
/* Written by GearTech Robots Trading */

#define knob A7
#define buzzer 2

void Liyab_Init()
{
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  tone(2, 1250, 350);
  tone(2, 1250, 350);
}

void OK() {
  pinMode(13, INPUT_PULLUP);
  while(digitalRead(13) == 0) {
    digitalWrite(13, 0);
    delay(100);
    digitalWrite(13, 1);
  }
}

void motor(uint8_t pin, int speed) {

  if (pin == 1)
  {
    if (speed > 0)
    {
      int spd = map(speed, 0, 100, 0, 255);
      analogWrite(9, spd);
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
    }

    if (speed < 0)
    {
      int spd = map(speed, 0, -100, 0, 255);
      analogWrite(9, spd);
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
    }
  }

  if (pin == 2)
  {
    if (speed > 0)
    {
      int spd = map(speed, 0, 100, 0, 255);
      analogWrite(10, spd);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
    }

    if (speed < 0)
    {
      int spd = map(speed, 0, -100, 0, 255);
      analogWrite(10, spd);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
    }
  }
}

void motor_stop()
{
  analogWrite(9, 0);
  analogWrite(10, 0);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}
