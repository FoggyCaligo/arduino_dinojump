
#include "lcd_manager.h"
#include "obstacle.h"



//Bird bird;

bool board[8][40]={0,};



void setup() {
  Serial.begin(9600);

  lcd.begin(16,2);
  lcd.backlight();
  lcd.init();
  lcd.home();

  //*/  
  for(int y=0; y<8; y++){
    for(int x=0;x<40; x++){
      board[y][x] = 1;
    }
  }
  //*/



  //update_lcd(board);
}

bool flag = false;

void loop() {
  

  if(flag==true){
       for(int ly=0; ly<4; ly++){
      for(int lx=0; lx<40; lx++){
        board[ly][lx] = 1;
      }
    }
    flag=false;
  }
  else{
    for(int ly=0; ly<4; ly++){
      for(int lx=0; lx<40; lx++){
        board[ly][lx] = 0;
      }
    }
    flag=true;
  }
  update_lcd(board);
  
  
}



