#include <LiquidCrystal_I2C.h>
//#include "lcd.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);   // I2C lcd 주소값 확인 , 16문자에 , 2열



byte to_byte(String answer){
  if(answer=="00000"){return 0b00000;}
    else if(answer=="01000"){return 0b01000;}
    else if(answer=="00100"){return 0b00100;}
    else if(answer=="00010"){return 0b00010;}
    else if(answer=="00001"){return 0b00001;}
    else if(answer=="01100"){return 0b01100;}
    else if(answer=="01010"){return 0b01010;}
    else if(answer=="01001"){return 0b01001;}
    else if(answer=="01100"){return 0b01100;}
    else if(answer=="01110"){return 0b01110;}
    else if(answer=="01101"){return 0b01101;}
    else if(answer=="01111"){return 0b01111;}
    else if(answer=="00101"){return 0b00101;}

    else if(answer=="10000"){return 0b10000;}
    else if(answer=="11000"){return 0b11000;}
    else if(answer=="10100"){return 0b10100;}
    else if(answer=="10010"){return 0b10010;}
    else if(answer=="10001"){return 0b10001;}
    else if(answer=="11100"){return 0b11100;}
    else if(answer=="11010"){return 0b11010;}
    else if(answer=="11001"){return 0b11001;}
    else if(answer=="11100"){return 0b11100;}
    else if(answer=="11110"){return 0b11110;}
    else if(answer=="11101"){return 0b11101;}
    else if(answer=="11111"){return 0b11111;}
    else if(answer=="10101"){return 0b10101;}
}






void update_lcd(bool board[8][40]){
  for(int pxNo=0; pxNo<8; pxNo++){//일렬로 된 8개의 칸
    byte curr_c[8];//커스텀문자 하나
    for(int ly=0; ly<8; ly++){//커스텀문자 안의 픽셀 8줄
      String str = "";
      for(int lx=0; lx<5; lx++){//1줄에 있는 픽셀 5개
        str+=String(board[ly][lx+lx*5]);
        //Serial.println(str);
      }
      curr_c[ly]=to_byte(str);
    }
    lcd.createChar(pxNo,curr_c);
  }
  lcd.home();
  uint8_t arr[8] = {0,1,2,3,4,5,6,7};

  //lcd.write2(arr);
  //lcd.clear();

  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(6);
  lcd.write(7);
  

  // for(int pxNo=0; pxNo<8; pxNo++){
  //   lcd.write(pxNo);

  // }
  //delay(10);

}


