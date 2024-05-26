#include "obstacle.h"

class Node {
    Obstacle *data;
    Node* link;

public:
Node(Obstacle *d){
    data = d;
}
//void setData(Obstacle *d) {data = d;}
Obstacle getData(){return *data;}
Node* getLink() {return link;}
void setLink(Node*n) {link = n;}
};




class LinkedQueue{
    Node* front;
    Node* rear;
public:
LinkedQueue(){
    front = rear = NULL;
}


void push(Obstacle *obs){

    Node* n = new Node(obs);
    if(front == NULL && rear == NULL){
        front = n;
        rear = n;
    }
    else{
        rear->setLink(n); // rear 가 가리키는 노드의 link에 n의 주소를 대입한다.
        rear = n; // 그리고 rear가 n을 가리키게끔 한다.
    }
}

void pop(){
    Node* tmp = front;
    front = front->getLink(); // front가 가리키고 있는 노드의 link 값 즉, 다음 노드의 주소값을 front에 대입하여 front가 다음 노드를 가리키게 한다.
    delete tmp;
}
Obstacle search(int idx){
    Node* tmp = front;
    for(int i = 0; i<idx; i++){
      tmp = tmp->getLink();
    }
    return tmp->getData();
}


void display(){
    Node* tmp = front;
    while(tmp != NULL){
        while(tmp!=NULL){
            tmp = tmp->getLink();
        }
        
    }
    
}
};

