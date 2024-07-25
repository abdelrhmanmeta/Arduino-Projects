#include <LiquidCrystal.h>
LiquidCrystal lcd(34, 4, 3, 33, 2, 32);
void setup() { 
  lcd.begin(16, 2); 
}
void loop() {
  lcd.setCursor(0, 1);
}




