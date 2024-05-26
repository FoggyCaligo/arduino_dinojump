
//#include "lcd_manager.h"
//#include "obstacle.h"
#include "Map_test.h"
//#include "Queue.h"

//bool board[8][40]={1,};

void setup() {
  Serial.begin(9600);
  //Serial.println("setup start");


  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  //Serial.println("setup complete");

  int orig=3;
  int *ptr;
  
  ptr = &orig;

  // Serial.println(ptr);
  //Serial.println(*ptr);



}
Map gameMap;

void loop() {
  Serial.println("loop");

  gameMap.game_update();

  lcd_print();
}
