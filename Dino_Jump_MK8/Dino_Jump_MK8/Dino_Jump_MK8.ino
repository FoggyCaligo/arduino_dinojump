
//#include "lcd_manager.h"
//#include "obstacle.h"
#include "Map.h"
//#include "Queue.h"

//bool board[8][40]={1,};

int score = 1;
int lv = 1;
Dino dino;

bool is_jumping = false;
int jumpcount = 0;





void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(3,INPUT);
}



Map gameMap;





void loop() {

  int val = digitalRead(3);
  if(val==HIGH){
    is_jumping = true;
  }
  
  if(is_jumping == true){
    if(jumpcount<=4){
      dino.jump(jumpcount);
      jumpcount++;
    }
    else if(jumpcount>4){
      jumpcount = 0;
      is_jumping = false;
    }
    
  }
  else{
    dino.move();
  }


  if(dino.check_col()==true){
    lcd.clear();
    lcd.print("Game Over");
    // score = 1;
    // lv = 1;
    delay(3000);//게임 오버 화면 보여주기 위해 잠깐 정지
    
    lcd.clear();
    gameMap.game_restart();
  }
  else{
    gameMap.game_update(1);
    lcd_print(1,1);
  }



  
}

void jump(){
  is_jumping = true;
}
