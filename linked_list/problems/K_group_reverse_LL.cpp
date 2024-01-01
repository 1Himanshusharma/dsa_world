#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
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
      head = last = new_node;
    }
    else{
      last->next = new_node;
      last = new_node;
    }
  }
  Node *get_head(){
    return head;
  }

};
  int getlen(Node *head){
    int len = 0;
    Node *temp = head;
    while (temp){
      len++;
      temp = temp->next;
    }
    return len;
  }
  
Node *reverseKnodes(Node *head, int k) {
    // Base case: If the number of nodes is less than K, return the original list.
    if (head == NULL || getlen(head) < k) {
        return head;
    }
    
    Node *p, *q, *r;
    p = head; // Initialize p to the head of the linked list
    q = r = NULL;
    
    // Reverse the first k nodes
    for (int i = 0; i < k; i++) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    // Recursive call to reverse the next k nodes
    Node *sublistHead = reverseKnodes(p, k);
    head->next = sublistHead;

    return q; // q is the new head of the reversed sublist
}

  void display(Node *temp){
    while (temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
  }

  int main(){
    int n;
    cin >> n;
    LinkedList l1;
    for (int i=0 ;i<n ;i++){
      int data;
      cin >> data;
      l1.insert(data);
      }
      int k;
      cin >> k;
      Node *head = l1.get_head();
      Node *res = reverseKnodes(head ,k);
      display(res);

  }