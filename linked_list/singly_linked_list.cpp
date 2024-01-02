#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
  class Node(){
    this->data = 0;
    this->next = NULL;
  }
  class Node(int data){
    this->data = data;
    this->next = NULL;
  }
  ~Node(){
    cout << "Node with value: " << this->data << "deleted" << endl;
  }
};
void display(Node *head){
  Node *temp = head;
  while (temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
}
int getlength(Node *head){
  int len = 0;
  Node *temp = head;
  while (temp){
    temp = temp->next;
    len++;
  }
  return len;
}
void insertAtHead(Node* &head,Node* &tail,int data){
  // check if head == NULL
  if (head == NULL){
    //LL is empty
    Node *new_node = new Node(data);
    head = new_node;
    tail = head;
  }
  else{
    Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;
  }
}
Void insertAtTail(Node *head,Node* tail,int data){
  if (head == NULL){
    head = new Node(data);
    tail = head;
  }
  else{
    Node *new_node = new Node(data);
    tail->next = new_node;
    tail = new_node;
  }
}