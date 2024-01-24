#include<iostream>
using namespace std;
class L_Node{
  public:
  int data;
  L_Node* next;
};
class Queue{
  private:
  L_Node *front, *rear;
  public:
  Queue(){
    front == NULL;
    rear == NULL;
  }
  void enqueue(int val){
    // we can use unlimited space
    // so when we say that linked list is full
    // so when i allocate the dynamic memory. and that memory could not be allocated then i can say that linked list is full
    
  }
}