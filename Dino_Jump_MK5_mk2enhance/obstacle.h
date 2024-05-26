
#include"lcd_manager.h"



class Obstacle {
public:
  int x=45;
  int y=0;
  bool curr_form[8][5];
  bool design[8][5] = {0,};

  void move(){
    //기존 픽셀 삭제
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        bool get = lcd_getpx(ly+y,x-lx);
        if(lcd_getpx(ly+y,x-lx)==true && curr_form[ly][4-lx]==true){
          lcd_setpx(ly+y, x-lx, 0);
        }
      }
    }
    //한칸 뒤로 움직이기
    x-=1;
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        lcd_setpx(y+ly,x-lx,curr_form[ly][4-lx]);
        //Serial.println(x);
      }
    }
  }
};





class Bird : public Obstacle{
public:
  bool wing = true;
  bool box[8][5]={//
      {1,1,0,0,0},
      {0,1,1,1,1},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    };
  Bird(){
    //init curr_form from box
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        curr_form[ly][lx] = box[ly][lx];
      }
    }
    //set wing
    move_wing();
    // move & draw
    move();

  }
  move_wing(){
    if(wing==true){
      curr_form[0][3] = 1;
      curr_form[2][3] = 0;
      wing = false;
    }
    else{
      curr_form[0][3] = 0;
      curr_form[2][3] = 1;
      wing=true;
    }
  }
  void move(){
    move_wing();
    //기존 픽셀 삭제
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        bool get = lcd_getpx(ly+y,x-lx);
        if(lcd_getpx(ly+y,x-lx)==true && curr_form[ly][4-lx]==true){
          lcd_setpx(ly+y, x-lx, 0);
        }
      }
    }
    //한칸 뒤로 움직이기
    x-=1;
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        lcd_setpx(y+ly,x-lx,curr_form[ly][4-lx]);
        //Serial.println(x);
      }
    }
  }
};

Bird bird;







class tree_short : public Obstacle{
public:
  bool wing = true;
  bool box[8][5]={//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,0,0},
      {0,0,1,0,0}
    };
  tree_short(){
    //init curr_form from box
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        curr_form[ly][lx] = box[ly][lx];
      }
    }
    move();
  }
};


class tree_long : public Obstacle{
public:
  bool wing = true;
  bool box[8][5]={//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,0,0},
      {0,0,1,0,0},
      {0,0,1,0,0}
  };

  tree_long(){
    //init curr_form from box
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        curr_form[ly][lx] = box[ly][lx];
      }
    }
    move();
  }
};



class Rock : public Obstacle{
public:
  bool wing = true;
  bool box[8][5]={//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,1,1,1,0},
      {0,1,1,1,0}
  };
  
  Rock(){
    //init curr_form from box
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        curr_form[ly][lx] = box[ly][lx];
      }
    }
    move();
  }
};