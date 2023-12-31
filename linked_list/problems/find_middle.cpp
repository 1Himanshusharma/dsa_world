#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
};
class LinkedList{
  private:
  Node *head,*last;
  public:
  LinkedList(){
    head = NULL;
    last = NULL;
  }
  void insert(int val){
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL){
      head =  new_node;
      last = head;
    }
    else{
      last->next = new_node;
      last = new_node;
    }
  }
  Node * findmiddle(){
    if (head == NULL){
      return head;
    }
    if (head->next == NULL){
      return head;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next) {
      slow = slow -> next;
      fast = fast->next->next;
      }
      return slow;

  }
};
int main(){
  int n;
  cout << "Enter the length of linked list: ";
  cin >> n;
  LinkedList lnklist;
  cout << "Enter elements in linked list:"<<endl;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    lnklist.insert(x);
    }
    Node *mid = lnklist.findmiddle();
    cout << "The middle element is :" << mid->data ;
    
}