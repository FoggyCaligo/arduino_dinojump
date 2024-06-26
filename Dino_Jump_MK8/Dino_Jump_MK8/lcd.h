#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27, 16, 2);   // I2C lcd 주소값 확인 , 16문자에 , 2열

LiquidCrystal_I2C lcd(0x27, 20, 4);   // I2C lcd 주소값 확인 , 16문자에 , 2열

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

void lcd_clear(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      display[i].c[j] = B00000;
    }
  }
}

void lcd_print(int lv,int score){  
  for(int row=0; row<8; row++){ lcd.createChar(row, display[row].c); }
  lcd.home();
  for(int row=0; row<8; row++){ lcd.write(row);}
  // lcd.print("Lv");
  // lcd.print(lv);
  
  // lcd.setCursor(0, 1);
  // lcd.print("Score:");
  // lcd.print(score);
  
}

bool lcd_getpx(int boardy, int boardx){
  return bitRead(display[int(boardx/5)].c[boardy],4-boardx%5)==1?1:0;
}


void lcd_setpx(int boardy, int boardx, bool state){
  //if(!(boardy>=8 || boardx>=40)){
    if(state==0){bitClear(display[int(boardx/5)].c[boardy], 4-boardx%5);}
    //else if(state==1 && lcd_getpx(boardy,boardx)==0){bitSet  (display[int(boardx/5)].c[boardy], 4-boardx%5);}
    else if(state==1){bitSet  (display[int(boardx/5)].c[boardy], 4-boardx%5);}
  
  //}
  //else if(state==1&&state==0){bitSet  (display[int(boardx/5)].c[boardy], boardx%5);}
}





