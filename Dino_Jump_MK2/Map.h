#include "Queue.h"


class Map{
public:
  int speed = 600;
  LinkedQueue q;
  bool is_able = true;
  Obstacle empty;
  Bird bird;
  tree_long longtree;
  tree_short shorttree;
  Rock rock;
  bool past_kind = 0;//0:land 1:sky
  //Obstacle ob_arr[2];  //small tree / big tree/ mixed tree/ bird

  Map(){
    randomSeed(analogRead(0));
    //ob_arr[0] = bird;
    //set_startline
    for(int i =0; i<8; i++){
      q.push(empty);
    }
  }

  void update(){
    // for(int i = 0; i<8; i++){
    //   q.search(i).move();
    // }


    if(is_able==false){//gen empty
      int rand = int(random(2,5));
      for(int i=0; i<rand; i++){
        q.push(empty);
        is_able = true;
      }
    }

    bool updown = bool(random(0,1));
    if(updown==0){//gen land_obs
      int kindof = int(random(0,2));
      if(kindof==0){
        q.push(shorttree);
      }
      else if(kindof==1){
        q.push(longtree);
      }
      else if(kindof==2){
        q.push(rock);
      }
      is_able = false;
    }
    else if(updown==1){//gen sky_obs
      int howmuch = int(random(1,3));
      for(int i=0; i<howmuch; i++){
        q.push(bird);
      }

      is_able = false;
    }
    q.pop();
  }

  
};