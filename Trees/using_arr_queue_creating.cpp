#include<iostream>
using namespace std;

class Queue{
  private:
  int size;
  int *Q;
  int front,rear;
  public:
  public:
  Queue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
  }
  ~Queue(){
    delete Q;
  }
  bool is_full(){
    if (rear == size - 1){
      return true;
    }
    return false;
  }
  bool is_empty(){
    if (front == rear){
      return true;
    }
    return false;
  }
  void enqueue(int key){
    if (is_full()){
      cout << "Queue is full.";
    }
    else{
      rear++;
      Q[rear] = key;
    }
  }
  int dequeue(){
    int temp = 0;
    if (is_empty()){
      cout << "Queue is empty.";
    }
    else{
      front++;
      temp = Q[front];
    }
    return temp;
  }
};


// now i am gonna create