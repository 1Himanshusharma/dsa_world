#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
  Node(){
    this->data = 0;
    this->next = NULL;
  }
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
  ~Node(){
    cout << "Node with value: " << this->data << " deleted " << endl;
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
void insertAtTail(Node *&head,Node* &tail,int data){
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
void insertAtPosition(Node* &head,Node* &tail,int data,int index){
  //suppose head == NULL
  if (head == NULL){
    Node *new_node = new Node(data);
    head = new_node;
    tail = head;
  }
  else {
    if (index == 1){
      insertAtHead(head,tail,data);
      return;
    }
    int len = getlength(head);
    if (index > len){
      insertAtTail(head,tail,data);
      return;
    }
    int i = 1;
    Node *p,*q;
    p = head;
    q = NULL;
    while (index > 1){
      q = p;
      p = p->next;
      index--;
    }
    Node *new_node = new Node(data);
    new_node->next = p->next;
    q->next = new_node;
  }
}
void deleteFromIndex(Node* &head, Node* &tail, int index) {
  if (head == NULL) {
    cout << "LL is empty.";
    return;
  }

  int len = getlength(head);

  if (index <= 0 || index > len) {
    cout << "Invalid Index";
    return;
  }

  if (index == 1) {
    Node *temp = head;
    head = head->next;
    if (head == NULL) {
      tail = NULL; // Update tail when the list becomes empty
    }
    delete temp;
  } else {
    int i = 1;
    Node *p = head;
    Node *q = NULL;

    while (i < index) {
      q = p;
      p = p->next;
      i++;
    }

    q->next = p->next;

    if (q->next == NULL) {
      tail = q; // Update tail if the last element is deleted
    }

    delete p;
  }
}

int main(){
  Node *head = NULL;
  Node *tail = NULL;
  insertAtHead(head,tail,10);
  insertAtHead(head,tail,20);
  insertAtHead(head,tail,10);
  insertAtHead(head,tail,20);
  insertAtHead(head,tail,10);
  insertAtHead(head,tail,20);
  insertAtHead(head,tail,10);
  insertAtTail(head,tail,20);
  insertAtTail(head,tail,10);
  insertAtTail(head,tail,20);
  insertAtTail(head,tail,10);
  insertAtTail(head,tail,20);
  insertAtTail(head,tail,10);
  insertAtTail(head,tail,20);
  insertAtTail(head,tail,10);
  insertAtTail(head,tail,20);
  deleteFromIndex(head,tail,3);
  display(head);
}