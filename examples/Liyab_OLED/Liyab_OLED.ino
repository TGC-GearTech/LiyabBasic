/* Liyab Basic Microcontroller - OLED Display */

// NOTE: Make Sure to Install Adafruit GFX Library and Adafruit SSD1306 Library to make OLED work

#include <LiyabBasic.h>

void setup() {
  Liyab_Init();
  OK();

}

void loop() {
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.println("Hello, world!");
  oled.display();

  /* To Clear Display, use these codes:
  oled.clearDisplay();
  oled.display(); */
}
