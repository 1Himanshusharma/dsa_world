#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *lchild;
  Node *rchild;
  Node(int key){
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};
class LNode{
  public:
  int data;
  LNode *next;
  LNode(int key){
    this->data = key;
    this->next = NULL;
  }
}

class Queue{
  private:
  LNode *front,*rear;
  public:
  Queue(){
    front = rear = NULL;
  }
  void enqueue(int key){
    LNode *new_node = LNode(key);
    if (new_node == NULL){
      cout << "Can't create buffer overflow.";
    }
    else{
      if (front == NULL){
        front = new_node;
        rear = new_node;
      }
      else{
        rear->next = new_node;
        rear = new_node;
      }
    }
  }
  LNode *dequeue(){
    LNode *temp = NULL;
    if (front == NULL){
      cout << "Queue is empty.";
    }
    else{
      temp = front->data;
      front = front->next;
    }
    return temp;
  }
  bool isempty(){
    if ()
  }
}