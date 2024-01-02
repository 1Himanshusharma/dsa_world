#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node *prev;
  Node(){
    this->data = 0;
    this->next = NULL;
    this->prev = NULL; // Fix: Change 'this->next' to 'this->prev'
  }
  Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

void display(Node *head){
  while (head){
    cout << head->data << " ";
    head = head->next;
  }
}

int getLength(Node *head){
  int len = 0;
  while (head){
    len++;
    head = head->next;
  }
  return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
  if (head == NULL){
    head = new Node(data);
    tail = head;
  }
  else{
    Node *new_node =  new Node(data);
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
  }
}

void insertAtTail(Node* &head, Node* &tail, int data){
  if (head == NULL){
    head = new Node(data);
    tail = head;
  }
  else{
    Node *new_node = new Node(data);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int index){
  if (head == NULL){
    head = new Node(data);
    return;
  }
  if (index == 1){
    insertAtHead(head, tail, data);
    return;
  }
  int len = getLength(head);
  if (index == len + 1){ // Fix: Change 'index == len' to 'index == len + 1'
    insertAtTail(head, tail, data);
    return;
  }
  else{
    Node *p, *q;
    p = head;
    q = NULL;
    int i = 1;
    while (i < index - 1){
      q = p;
      p = p->next;
      i++;
    }
    Node *new_node = new Node(data);
    q->next = new_node;
    new_node->prev = p->prev;
    new_node->next = p;
    p->prev = new_node; // Fix: Add this line to update the previous pointer of the next node
  }
}

void deleteAtPosition(Node* &head, Node* &tail, int index){
  if (head == NULL){
    cout << "Linked list is empty: ";
    return;
  }
  if (index == 1){
    Node *temp = head;
    head = head->next;
    if (head != NULL) // Fix: Add this condition to check if head is not NULL
      head->prev = NULL;
    delete temp;
  }
  else{
    Node *p = head;
    Node *q = NULL;
    while (index > 1){
      q = p;
      p = p->next;
      index--;
    }
    q->next = p->next;
    if (p->next != NULL) // Fix: Add this condition to check if p->next is not NULL
      p->next->prev = q;
    delete p;
  }
}

int main(){
  Node *head = NULL;
  Node *tail = NULL;
  insertAtHead(head, tail, 10);
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 10);
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 10);
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 10);
  insertAtTail(head, tail, 20);
  insertAtTail(head, tail, 10);
  insertAtTail(head, tail, 20);
  insertAtTail(head, tail, 10);
  insertAtTail(head, tail, 20);
  insertAtTail(head, tail, 10);
  insertAtTail(head, tail, 20);
  insertAtTail(head, tail, 10);
  insertAtTail(head, tail, 20);
  deleteAtPosition(head, tail, 1);
  display(head);
  return 0;
}
