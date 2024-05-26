#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);   // I2C lcd 주소값 확인 , 16문자에 , 2열

void DrawLine(int x, int y, int length, bool hori, bool isSet);

struct Display {
  byte c[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
};

Display display[8];


//print 2 display
void lcd_print(){
  // for(int row=0; row<8; row++){
  //   lcd.createChar(row, display[row].c);
  // }
  lcd.createChar(0, display[0].c);
  lcd.createChar(1, display[1].c);
  lcd.createChar(2, display[2].c);
  lcd.createChar(3, display[3].c);
  lcd.createChar(4, display[4].c);
  lcd.createChar(5, display[5].c);
  lcd.createChar(6, display[6].c);
  lcd.createChar(7, display[7].c);
  //lcd.clear();
  lcd.home();
  //lcd.setCursor(0,0);

  // for(int row=0; row<8; row++){
  //   lcd.write(row);
  // }
  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
}

bool lcd_getpx(int boardy, int boardx){
  return bitRead(display[int(boardx/5)].c[boardy],4-boardx%5)==1?1:0;
}
void lcd_setpx(int boardy, int boardx, bool state){
  if(boardy>=8 || boardx>=40){return;}

  if(state==0){bitClear(display[int(boardx/5)].c[boardy], 4-boardx%5);}
  else if(state==1 && lcd_getpx(boardy,boardx)==0){bitSet  (display[int(boardx/5)].c[boardy], 4-boardx%5);}
  //else if(v==1&&state==0){bitSet  (display[int(boardx/5)].c[boardy], boardx%5);}
}

