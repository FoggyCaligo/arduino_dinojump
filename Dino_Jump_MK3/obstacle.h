
#include"lcd_manager.h"



class Obstacle {
public:
  int x=45;
  int y=0;
  byte curr_form[8];
};





class Bird : public Obstacle{
public:
  bool wing = true;
  byte c[8] = {
    B11010,
    B01111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
  };
  Bird(){
    for(int i=0; i<8; i++){
      curr_form[i] = c[i];
    }
    //set wing
    move_wing();
  }
  move_wing(){
    if(wing==true){
      bitSet(curr_form[0],3);
      bitSet(curr_form[2],3);
      wing = false;
    }
    else{
      bitSet(curr_form[0],3);
      bitSet(curr_form[2],3);
      wing=true;
    }
  }
};


class tree_short : public Obstacle{
public:
  byte c[8] = {
    B11000,
    B01111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00100,
    B00100
  };
  
  tree_short(){
    for(int i=0; i<8; i++){
      curr_form[i] = c[i];
    }
  }
};




class tree_long : public Obstacle{
public:
  byte c[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00100,
    B00100,
    B00100
  };
  
  tree_long(){
    for(int i=0; i<8; i++){
      curr_form[i] = c[i];
    }
  }
};


class Rock : public Obstacle{
public:
  byte c[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B01110,
    B01110
  };
  Rock(){
    for(int i=0; i<8; i++){
      curr_form[i] = c[i];
    }
  }
};

