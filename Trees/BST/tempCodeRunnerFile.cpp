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

Node *insert(Node *p,int key){
  Node *t;
  if (p == NULL){
    t = new Node(key);
  }
  if (key < p->data){
    p->lchild = insert(p->lchild,key);
  }
  else if (key > p->data){
    p->rchild = insert(p->rchild,key);
  }
  return t;
}
void preorder(Node *p){
  if (p){
    cout << p->data << " ";
    preorder(p->lchild);
    preorder(p->rchild);
  }
}
int main(){
  Node *root = NULL;
  root = insert(root,50);
  root = insert(root,30);
  root = insert(root,20);
  root = insert(root,40);
  root = insert(root,10);
  cout<<"PreOrder Traversal of constructed tree is \n";
  preorder(root);
  
}