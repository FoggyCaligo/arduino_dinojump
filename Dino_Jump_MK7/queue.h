
class Node{
  Obstacle data;
  Node *link;
public:
  Node(Obstacle d){
    data d
  }
  void setData(Obstacle d){data = d;}
  Obstacle getData(){return &data;}//Obstacle *received = q.getData();
  Node* getLink(){return link;}
  void setLink(Node *n){link = n;}
}



class LinkQueue{
  Node* front;
  Node* rear;
public:
  LinkQueue(){
    front = rear = NULL;
  }
  void push(Obstacle obs){

  }

}