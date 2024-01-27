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
};

class Queue{
  private:
  LNode *front,*rear;
  public:
  Queue(){
    front = rear = NULL;
  }
  void enqueue(int key){
    LNode *new_node = new LNode(key);
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
      temp = front;
      front = front->next;
    }
    return temp;
  }
  bool isempty(){
    if (front == NULL){
      return NULL;
    }
  }
  bool isfull(){
    LNode *new_node = new LNode(7);
    if (new_node == NULL){
      return true;
    }
    return false;
  }
  void display(){
    LNode *temp = front;
    while (temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
};
int main(){
  cout << "Please enter the values and (enter -1 to stop): ";
  Queue q;
  while (true){
    int key;
    cin >> key;
    if (key == -1){
      break;
    }
    q.enqueue(key);
  }
  //display
  cout << "The elements in queue are: \n";
  q.display();
}
