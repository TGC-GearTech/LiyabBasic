/* Liyab Bluetooth RC Code */

// NOTE: Only Connect the TX of Bluetooth Receiver to D6. In this case, we use software serial library to avoid using serial pins of arduino
// No need to Press OK button!

#include <SoftwareSerial.h>
#include <LiyabBasic.h>

#define rxPin 6
#define txPin 5

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup()  {
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    mySerial.begin(9600);
    Liyab_Init();
}

void loop() {
    if (mySerial.available() > 0)
    {
        char command = mySerial.read();
        Serial.println(command);
        
        if (command == 'F')
        {
            motor(1, 100);
            motor(2, 100);
        }
        
        if (command == 'B')
        {
            motor(1, -100);
            motor(2, -100);
        }
        
        if (command == 'L')
        {
            motor(1, -100);
            motor(2, 100);
        }

        if (command == 'R')
        {
            motor(1, 100);
            motor(2, -100);
        }
        
        if (command == 'I')
        {
            motor(1, 100);
            motor(2, 0);
        }
        
        if (command == 'G')
        {
            motor(1, 0);
            motor(2, 100);
        }
        
        if (command == 'H')
        {
            motor(1, 0);
            motor(2, -100);
        }
        
        if (command == 'J')
        {
            motor(1, -100);
            motor(2, 0);
        }
        
        if (command == 'S')
        {
            motor(1, 0);
            motor(2, 0);
        }
    }
}
