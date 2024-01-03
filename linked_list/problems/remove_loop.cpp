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
bool check_loop(Node* head){
  if (head == NULL){
    return false;
  }
  if (head->next == NULL){
    return false;
  }
  Node* slow = head;
  Node* fast = head;
  while (fast){
    fast= fast->next;
    if (fast){
      fast = fast->next;
      slow = slow->next;
    }
    if (slow == fast){
      return true;
    }
  }
  return false;
}
Node* start_node(Node* head){
  if (head == NULL){
    return NULL;
  }
  if (head->next == NULL){
    return head;
  }
  Node *slow = head;
  Node *fast = head;
  while (fast){
    fast = fast->next;
    if (fast){
      fast = fast->next;
      slow = slow->next;
    }
    if (slow == fast){
      slow = head;
      break;
    }
  }
  while (fast && slow != fast){
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
}

void remove_node(Node* &head){
  if (head == NULL){
    cout << "LL is not empty.";
    return;
  }
  if (head->next == NULL){
    cout << "LL have one singel Node.";
  }
  Node* slow = head;
  Node* fast = head;
  Node* prev = NULL;
  while (fast){
    prev = fast;
    fast = fast->next;
    if (fast){
      fast = fast->next;
      slow = slow->next;
    }
    if (slow == fast){
      break;
    }
  }
  prev->next = NULL;

}

int main(){
  Node *head = NULL;
  Node *tail = NULL;
  insertAtHead(head,tail,10);
  insertAtHead(head,tail,20);
  insertAtHead(head,tail,30);
  insertAtHead(head,tail,40);
  insertAtHead(head,tail,50);
  insertAtHead(head,tail,60);
  insertAtHead(head,tail,70);
  insertAtTail(head,tail,80);
  insertAtTail(head,tail,90);

  tail->next = head->next->next->next->next;

  bool ans = check_loop(head);
  if (ans){
    cout << "Loop founded" << endl;
  }
  else{
    cout << "loop not founded" << endl;
  }
  Node* temp = start_node(head);
  cout << "starting node is: " << temp->data << endl;
  remove_node(head);
  display(head);
}