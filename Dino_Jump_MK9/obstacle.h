
#include"lcd_manager.h"




class Dino{
public:
  bool wing = true;
  bool orig[8][5]={//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,0,0,0}
  };

  bool form[4][5]={
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,0,0,0}
  };
  
  bool curr_form[8][5]={//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,0,0,0}
  };
  
   bool col_mask[8][5]={//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,0,0,1},
      {0,0,0,1,0},
      {1,0,0,1,0},
      {1,0,0,0,0}
  };
  bool orig_mask[8][5]={//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,0,0,1},
      {0,0,0,1,0},
      {1,0,0,1,0},
      {1,0,0,0,0}
  };
  bool jump_form[5][8][5]={
    {//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,0,0,0}
    },
    {//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
      
    },
    {//
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    },
    {//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
      
    },
    {//
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,1,1,0},
      {1,1,1,0,0},
      {0,1,1,0,0},
      {0,0,0,0,0}
    }
  };




  Dino(){
    //init curr_for
  }

  bool flag = true;
  void move(){
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        if(lcd_getpx(ly,lx)==0 && curr_form[ly][lx]==1){
          lcd_setpx(ly,lx,1);
        }
      }
    }
    //move_leg
    if(flag==true){
      lcd_setpx(7,2,1);
      lcd_setpx(7,1,0);
      flag = false;
    }
    else{
      lcd_setpx(7,2,0);
      lcd_setpx(7,1,1);
      flag=true;
    }
  }

  void jump(int process){
    if(process==1 || process==3){
      //위로 옮겨 그리기
      for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
          curr_form[8-i+2][j] = form[8-i][j];
          col_mask[8-i+2][j] = col_mask[8-i][j];
        }
      }
      //아래부분 지우기
      for(int i =0; i<4; i++){
        for(int j=0; j<5; j++){
          curr_form[8-i][j] = 0;
          col_mask[8-i][j] = 0;
        }
      }
    }
    else if(process==2){
      //위로 옮겨 그리기
      for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
          curr_form[8-i+3][j] = form[8-i+2][j];
          col_mask[8-i+3][j] = col_mask[8-i+2][j];
        }
      }
      //아래부분 지우기
      for(int i =0; i<5; i++){
        for(int j=0; j<5; j++){
          curr_form[i][j] = 0;
          col_mask[i][j] = 0;
        }
      }
    }
    else if(process==0 || process==4){
      for(int i=0; i<8; i++){
        for(int j=0; j<5; j++){
          curr_form[i][j] = orig[i][j];
          col_mask[i][j] = orig_mask[i][j];
        }
      }
    }

    //실제로 그리기
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        if(lcd_getpx(ly,lx)==0 && col_mask[ly][lx]==1){
          lcd_setpx(ly,lx,1);
        }
      }
    }

  }
  bool check_col(){
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        if(lcd_getpx(ly,lx)==1 && col_mask[ly][lx]==1){
          lcd.print("Game Over");
          return true;
        }
      }
    }
    return false;
  }
};



class Obstacle {
public:
  int x=45;
  int y=0;
  bool curr_form[8][5];
  bool design[8][5] = {0,};

  // bool flag = true;


  // void move(int y1,int x1, int y2, int x2){
  //   if(flag==true){
  //     curr_form[y1][x1] = 1;
  //     curr_form[y2][x2] = 0;
  //     flag = false;
  //   }
  //   else{
  //     curr_form[y1][x1] = 0;
  //     curr_form[y2][x2] = 1;
  //     flag=true;
  //   }


  //   //기존 픽셀 삭제
  //   for(int ly=0; ly<8; ly++){
  //     for(int lx=0; lx<5; lx++){
  //       bool get = lcd_getpx(ly+y,x-lx);
  //       if(lcd_getpx(ly+y,x-lx)==true && curr_form[ly][4-lx]==true){
  //         lcd_setpx(ly+y, x-lx, 0);
  //       }
  //     }
  //   }
  //   //한칸 뒤로 움직이기
  //   x-=1;
  //   for(int ly=0; ly<8; ly++){
  //     for(int lx=0; lx<5; lx++){
  //       lcd_setpx(y+ly,x-lx,curr_form[ly][4-lx]);
  //       //Serial.println(x);
  //     }
  //   }

  // }
  
  
  
  
  
  void move(int amount){
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
    x-=amount;
    for(int ly=0; ly<8; ly++){
      for(int lx=0; lx<5; lx++){
        if(curr_form[ly][4-lx]==1){
          lcd_setpx(y+ly,x-lx,curr_form[ly][4-lx]);
        //Serial.println(x);
        }
        
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
    //move_wing();
    // move & draw
    //move();

  }
  // void move_wing override(){
  //   if(wing==true){
  //     curr_form[0][3] = 1;
  //     curr_form[2][3] = 0;
  //     wing = false;
  //   }
  //   else{
  //     curr_form[0][3] = 0;
  //     curr_form[2][3] = 1;
  //     wing=true;
  //   }
  // }

  // void move(){
  //   //move_wing();
  //   if(wing==true){
  //     curr_form[0][3] = 1;
  //     curr_form[2][3] = 0;
  //     wing = false;
  //   }
  //   else{
  //     curr_form[0][3] = 0;
  //     curr_form[2][3] = 1;
  //     wing=true;
  //   }
    
    
    
    
    
  //   //기존 픽셀 삭제
  //   for(int ly=0; ly<8; ly++){
  //     for(int lx=0; lx<5; lx++){
  //       bool get = lcd_getpx(ly+y,x-lx);
  //       if(lcd_getpx(ly+y,x-lx)==true && curr_form[ly][4-lx]==true){
  //         lcd_setpx(ly+y, x-lx, 0);
  //       }
  //     }
  //   }
  //   //한칸 뒤로 움직이기
  //   x-=1;
  //   for(int ly=0; ly<8; ly++){
  //     for(int lx=0; lx<5; lx++){
  //       lcd_setpx(y+ly,x-lx,curr_form[ly][4-lx]);
  //       //Serial.println(x);
  //     }
  //   }

  // }
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
  }
};