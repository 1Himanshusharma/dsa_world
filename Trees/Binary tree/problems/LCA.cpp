#include<iostream>
using namespace std;
#include<queue>
class Node{
  public:
  int data;
  Node *rchild;
  Node *lchild;
};
class BT{
  private:
  Node* root;
  // Function to create a new node.
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root value: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *temp = q.front();
      q.pop();
      int key;
      cout << "Please enter the left child of : " << temp->data << " : ";
      cin >> key;
      if (key != -1){
        temp->lchild = new Node(key);
        q.push(temp->lchild);
      }
      cout << "please enter the right child of : " << temp->data << " : ";
      cin >> key;
      if (key != -1){
        temp->rchild = new Node(key);
        q.push(temp->rchild);
      }
    }
  }
  void inorder(){
    inorder(root);
  }
}