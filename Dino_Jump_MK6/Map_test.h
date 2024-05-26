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
  int end_count = 0;

  Map(){
    randomSeed(analogRead(0));
    q.push(Bird());

    
  }

  void game_update(){
    for(int i = 0; i<sizeof(q); i++){
      q.search(0)->move();
    }



    end_count++;
    if(end_count>=45){
      //새로운 블럭 만들고 기존 블럭 삭제
      q.push(Bird());

      q.pop();
      end_count = 0;
    }
     //Serial.println("move obs");
    

  }
  
};