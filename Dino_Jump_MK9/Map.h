#include "Queue.h"


class Map{
public:
  int speed = 600;
  LinkedQueue q;
  // Bird bird;
  // tree_long longtree;
  // tree_short shorttree;
  // Rock rock;
  Obstacle empty;
  
  bool is_able = true;
  bool is_passed = true;
  int line_count = 0;
  int land_count = 0;



  Map(){
    randomSeed(analogRead(0));
    for(int i = 0; i<sizeof(q); i++){
      q.push(empty);
    }
  }

  void update(){
    for(int i = 0; i<8; i++){
      q.search(i).move();
    }
    if(is_passed == true && is_able==true){//빈칸으로 띄워졌으면 새로운 칸 만들기
      bool updown = bool(random(0,1));
      if(updown == 0){
        int kindof = int(random(0,2));
        if(kindof==0){
          q.push(tree_short());
        }
        else if(kindof==1){
          q.push(tree_long());
        }
        else if(kindof==2){
          q.push(Rock());
        }
      }
      else if(updown==1){//gen sky_obs
        q.push(Bird());
      }
      // int howmuch = int(random(1,3));
      // for(int i=0; i<howmuch; i++){
      //   q.push(bird);
      // }
      q.pop();
      is_passed = false;
      is_able = false;
      //Serial.println("generated");
    }
    else if(is_passed==true && is_able==false){ //점프하고 착지할 land 공간 생성
      land_count ++;
      if(land_count>=5){
        land_count=0;
        is_able = true;
      }
      //Serial.println("gen land");
    }
    else{// 빈칸 나올 때 까지 obs 움직이기
      line_count++;
      if(line_count>=5){
        line_count = 0;
        is_passed = true;
      }
      //Serial.println("move obs");
    }

  }
  
};