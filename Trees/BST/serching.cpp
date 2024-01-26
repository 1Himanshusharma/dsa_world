#include<iostream>
using namespace std;


class Node{
  public:
  int data;
  Node *lchild;
  Node *rchild;
  Node(int key){
    this->data = key;
    this->rchild = NULL;
    this->lchild = NULL;
  }
};

// return in true and false;
bool search(Node *p,int key){
  if (p == NULL){
    return false;
  }
  if (key == p->data){
    return true;
  }
  if (key < p->data){
    return search(p->lchild,key);
  }
  else if (key > p->data){
    return search(p->rchild,key);
  }
  return false;
}
Node *insert(Node *p,int key){
  Node *temp;
  if (p == NULL){
    temp = new Node(key);
    return temp;
  }
  if (p->data > key){
    temp->lchild = insert(p->lchild,key);
  }
  else if (p->data < key){
    temp->rchild = insert(p->rchild,key);
  }
  return temp;
}
void inorder(Node *p){
  if (p){
    inorder(p->lchild);
    cout << p->data << " ";
    inorder(p->rchild);
  }
}

int main(){
  Node *root = NULL;
  root = insert(root,30);
  root = insert(root,10);
  root = insert(root,20);
  root = insert(root,40);
  //cout<<search(root,15)<<endl;
  inorder(root);

  cout << search(root,50);
}