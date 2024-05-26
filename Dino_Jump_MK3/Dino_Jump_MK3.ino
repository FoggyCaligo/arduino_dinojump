
//#include "lcd_manager.h"
//#include "obstacle.h"
#include "Map.h"
//#include "Queue.h"

//bool board[8][40]={1,};
//Map gameMap;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
}

bool flag = false;




void loop() {
  //test----------------------------------------
  // if(flag==false){
  //   for(int ly=0; ly<8; ly++){
  //     for(int lx=0; lx<40; lx++){
  //       lcd_setpx(ly,lx,1);
  //       //delay(10);
  //     }
  //   }
  //   flag=true;
  // }
  // else{
  //   for(int ly=0; ly<4; ly++){
  //     for(int lx=0; lx<40; lx++){
  //       lcd_setpx(ly,lx,0);
  //       //delay(10);
  //     }
  //   }
  //   flag=false;
  // }



  //test----------------------------------------
  // for(int ly=0; ly<3; ly++){
  //   for(int lx=0; lx<21; lx++){
  //     lcd_setpx(ly,lx,1);
  //       //delay(10);
  //   }
  // }


  //delay(10);

  //gameMap.update();

  lcd_print();
}
