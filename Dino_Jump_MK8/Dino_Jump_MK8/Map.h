#include "Queue.h"



class Map{
public:
  int speed = 600;
  LinkedQueue q;


  Obstacle empty;


  bool is_able = true;
  bool is_passed = true;

  int pixel_end_count = 0;

  Map(){
    randomSeed(analogRead(0));
    // q.push(Bird());
    // q.push(tree_short());/
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
  }
  void game_restart(){
    for(int i=0; i<8; i++){
      q.pop();
    }
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    q.push(Obstacle());
    pixel_end_count = 0;
  }

  void game_update(int lv){
    int r = random(1,10);
    if(pixel_end_count>=r*15){
      gen();
      q.pop();
      pixel_end_count = 0;
    }
    else{  
      pixel_end_count+=1;
    }
    move(1);

  
  }


  
  void move(int lv){
    // for(int i = 0; i<sizeof(q); i++){
    //   q.search(i)->move();
    // }
    for(int i=0; i<8; i++){
      q.search(i)->move(lv);
    }

  }

  void gen(){
    int r = random(0,15);
    if(r%2==1){gen_land();}
    else{gen_bird();}

  }
  void gen_land(){
    int r = random(2);
    if(r==0){
      q.push(tree_short());
    }
    else if(r==1){
      q.push(tree_long());
    }
    else if(r==2){
      q.push(Rock());
    }
  }
  void gen_bird(){
    q.push(Bird());
  }

  
};