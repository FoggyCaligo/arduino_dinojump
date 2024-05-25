#include<cppQueue.h>



class Obstacle {
public:
  bool box[8][5] = {0,};

};


Obstacle obs;

cppQueue q = (sizeof(Obstacle), 16, LIFO);




class Bird : public Obstacle{
public:
  bool wing = true;
  int x=40;
  int y=0;


  Bird(){
    bool box[8][5] = {//
      {1,1,0,0,0},
      {0,1,1,1,1},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    };
  }
  move_wing(){
    if(wing==true){
      box[0][3] = 1;
      box[2][3] = 0;
      wing = false;
    }
    else{
      box[0][3] = 0;
      box[2][3] = 1;
      wing=true;
    }
  }
};