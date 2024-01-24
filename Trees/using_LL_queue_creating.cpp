#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* lchild;
  Node* rchild;
}
class L_Node{
  public:
  Node* data;
  L_Node* next;
};
class Queue{
  private:
  L_Node *front, *rear;
  public:
  Queue(){
    front = NULL;
    rear = NULL;
  }
  void enqueue(Node  *val){
    // we can use unlimited space
    // so when we say that linked list is full
    // so when i allocate the dynamic memory. and that memory could not be allocated then i can say that linked list is full
    L_Node *new_node = new L_Node;
    if (new_node == NULL){
      cout << "Memory Error! Can't create a new node." << endl;
    }
    else {
      new_node->data = val;
      new_node->next = NULL;
      if (front == NULL){
        front = new_node;
        rear = front;
      }
      else{
        rear->next = new_node;
        rear = new_node;
      }
  }
  }
  Node *dequeue(){
    Node* x = 0;
    if (front == NULL){
      cout << "Error! Empty queue. Can't remove an element from it." <<
      endl;
    }
    else{
      x = front->data;
      L_Node *temp = front;
      front = front->next;
      delete temp;
    }
    return x;
  }

  bool is_full(){
    L_Node *new_node = new L_Node;
    if (new_node == NULL){
      return true;
    }
    return false;
  }
  bool isempty(){
    if (front == NULL){
      return true;
    }
    return false;
  }
  void display(){
    L_Node *ptr;
    ptr = front;
    while(ptr != NULL) {
      cout << ptr->data << " ";
      ptr = ptr->next;
      }
  }

};
class Tree{
  private:
  Node *root;
  public:
  Tree(){
    root = NULL;
  }
  void create(){
    cout << "Enter the root element: ";
    int root_ele;
    Queue q;
    cin >> root_ele;
    root = new Node;
    root->data = root_ele;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
    while (!q.isempty()){
      Node *temp = q.dequeue();
      int key;
      cout << "Enter the left child of the " << temp->data << ": ";
      cin >> key;
    }
    

  }
}


int main(){
  cout << "Enter your element \n To stop press -1: ";
  Queue q;
  while (true){
    int key;
    cin >> key;
    if (key == -1){
      break;
    }
    q.enqueue(key);
  }
  cout << "\nElements in the queue are : ";
  q.display();
}
