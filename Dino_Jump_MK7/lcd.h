#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);   // I2C lcd 주소값 확인 , 16문자에 , 2열


struct Display{
  byte c[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
  }
};

Display lcd_board[8];

void lcd_print(){
  for(int row=0; row<8; row++){ lcd.createChar(row, display[row].c); }
  lcd.home();
  for(int row=0; row<8; row++){ lcd.write(row); }
}

bool lcd_getpx(int boardy, int boardx){
  return bitRead(display[int(boardx/5)].c[boardy],boardx%5)==1?1:0;
}
void lcd_setpx(int boardy, int boardx, bool state){
  bool v = lcd_getpx(boardy,boardx);
  if(state==0){bitClear(display[int(boardx/5)].c[boardy], boardx%5);}
  else if(state==1 && v==0){bitSet  (display[int(boardx/5)].c[boardy], boardx%5);}
}