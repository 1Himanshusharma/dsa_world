#include<iostream>
using namespace std;
// if i want to rotate a linked list then there si few things that you can do
// first appraoch also having O(n2) time complexity


// every time go to the last the insert it at the head and update the head and decerse the count 
// we will be doing the same thing aain and again until we run out the k value



class Node{
  public:
  int data;
  Node *next;
  Node(int key){
    this->data = key;
    this->next = NULL;
  }
};
class LL{
  private:
  Node *head, *last;
  public:
  void insert(int key){
    if (head == NULL){
      head = new Node(key);
      last = head;
    }
    else{
      last->next = new Node(key);
      last = last->next;
    }
  }
  Node *get_root(){
    return head;
  }
};
int count(Node *node){
  int count = 0;
  while (node){
    count++;
    node = node->next;
  }
  return count;
}
// this is method 1 is actually a brute force appraoch
void rotateI(Node* &node,int k){
  if (node == NULL || node->next == NULL){
    return;
  }

  while (k){
    node *p = head;
    node *q = NULL;
    while (q->next){
      q = p;
      p = p->next;
    }
    q->next= NULL;
    p->next = head;
    head = p;
    --k;  
  }
}
// supposer i count the all the node
// now i will partation the list 
// so that every time when we call get_
Node *rotateII(Node *node,int key){
  int l_count = count(node);
  if (l_count == key || (key % l_count == 0) || (key == 0)){
    return head;
  }
  k = l_count - (k/l_count);
  Node *p = head;
  Node *q = NULL;
  while (p->next && k > 0){
            k--;
            q= p;
            p = p->next;
        }
        if (q != NULL && p!= NULL){
            ListNode *temp = q;
            q = q->next;
            temp->next = NULL;
            while (p->next){
                p = p->next;
            }
            p->next = head;
            head = q;

        }
        return head;
}


int main(){
  int n;
  LL l;
  cout << "Enter the element until you enter -1 to stop: ";
  while (true){
    cin >> n;
    if (n == -1){
      break;
    }
    l.insert(n);

  }
  Node *root = l.get_root();

}