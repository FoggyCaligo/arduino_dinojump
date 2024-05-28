// #include<Wire.h>/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);   // I2C lcd 주소값 확인 , 16문자에 , 2열



void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.print("test");
}

void loop() {
  // put your main code here, to run repeatedly:

}
