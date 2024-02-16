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
class BT{
  private:
  Node *root;
  public:
  BT(){
    root = NULL;
  }
  void create(){
    int root_ele;
    cout << "Please enter the root element: ";
    cin >> root_ele;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *current = q.front(); q.pop();
      int key;
      cout << "Please enter the lchild of " << current->data << " : ";
      cin >> key;
      if (key != -1){
        current->lchild = new Node(key);
        q.push(current->lchild);
      }
      cout << "Please enter the rchild of " << current->data << " : ";
      cin >> key;
      if (key != -1){
        current->rchild = new Node(key);
        q.push(current->rchild);
      }
    }

  }
  
}