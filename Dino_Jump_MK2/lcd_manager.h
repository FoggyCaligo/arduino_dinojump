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

// int y = 0; //8
// int x = 0; //40

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
  return bitRead(display[int(boardx/5)].c[boardy],boardx%5)==1?1:0;
}
void lcd_setpx(int boardy, int boardx, bool state){
  bool v = lcd_getpx(boardy,boardx);
  //if((v==0&&state==1) || (v==1&&state==0)){bitSet  (display[int(boardx/5)].c[boardy], boardx%5);}
  
  //if(v^state==true){bitSet  (display[int(boardx/5)].c[boardy], boardx%5);}

  if(state==0){bitClear(display[int(boardx/5)].c[boardy], boardx%5);}
  else if(state==1 && v==0){bitSet  (display[int(boardx/5)].c[boardy], boardx%5);}
  //else if(v==1&&state==0){bitSet  (display[int(boardx/5)].c[boardy], boardx%5);}
}






// void dp_print(bool board[8][40])
// {
//   //convert board 2 actual pixel
//   //conv_board2px(board);
//   for(int row=0; row<8; row++){   
//     for(int ly=0; ly<8; ly++){
//       for(int lx=0; lx<5; lx++){
//         display[row].c[ly][lx] = board[ly][lx+row*5];
//       }
//     }
//   }
//   //generate custom char
//   for(int i=0; i<8; i++){
//     lcd.createChar(i,display[i].c);
//   }
//   //set cursor to start location
//   lcd.setCursor(0, 0);
//   //draw custom characters which are parts of game board;
//   for(int i=0; i<8; i++){
//     lcd.write(byte(i));
//   }
// }








// void Dp_SetPixel(int x, int y, bool isOn)
// {
//   if(isOn)
//     bitSet  (display[x][y].grid[y%8],4-x%5);
//   else 
//     bitClear(zeichen[x/5][y/8].grid[y%8],4-x%5);
// }

// bool Dp_GetPixel(int x, int y)
// {
//   return bitRead(zeichen[x/5][y/8].grid[y%8],4-x%5)==1?true:false;
// }

// void Dp_DrawLine(int x, int y, int length, bool hori, bool isSet)
// {
//   for(int offset = 0; offset < length; offset++)
//   {
//     if(hori)
//       Dp_SetPixel(x + offset, y, isSet);
//     else
//       Dp_SetPixel(x, y + offset, isSet);
//   }
// }























// void SetPixel(int x, int y, bool isOn)
// {
//   if(isOn)
//     bitSet  (zeichen[x/5][y/8].grid[y%8],4-x%5);
//   else 
//     bitClear(zeichen[x/5][y/8].grid[y%8],4-x%5);
// }


// bool Dp_GetPixel(int x, int y)
// {
//   return bitRead(display[x/5][y/8].grid[y%8],4-x%5)==1?true:false;
// }



// void DrawLine(int x, int y, int length, bool hori, bool isSet)
// {
//   for(int offset = 0; offset < length; offset++)
//   {
//     if(hori)
//       Dp_SetPixel(x + offset, y, isSet);
//     else
//       Dp_SetPixel(x, y + offset, isSet);
//   }
// }