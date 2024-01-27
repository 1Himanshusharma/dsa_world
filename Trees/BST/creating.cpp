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

class BST{
  private:
  Node *root;
  void preorder(Node *p){
    if (p){
      cout << p->data << " ";
      preorder(p->lchild);
      preorder(p->rchild);
    }
  }
  void postorder(Node *p){
    if (p){
      postorder(p->lchild);
      postorder(p->rchild);
      cout << p->data << " ";
    }
  }
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  public:
  BST(){
    root = NULL;
  }
  void insert(int x){
    if (root == NULL){
      root = new Node(x);
    }
    else{
      Node *p,*q;
      p = root;
      q = NULL;
      while (p != NULL){
        q = p;
        if (x <= p -> data) {
          p = p -> lchild;
        }
        else{
          p = p->rchild;
        }
      }
      p = new Node(x);
      if (x > q->data){
        q->rchild = p;
      }
      else{
        q->lchild = p;
      }
    }
  }
  
  void preorder(){
    preorder(root);
  }
  void postorder(){
    postorder(root);
  }
  void inorder(){
    inorder(root);
  }
};
int main(){
  BST T;
  cout << "Enter the values and to stop press (-1):  ";
  while (true){
    int key;
    cin >> key;
    if (key == -1){
      break;
    }
    T.insert(key);
  }
  cout << "\nPreorder traversal: ";
  T.preorder();
  cout << endl;
  cout << "Postorder traversal: ";
  T.postorder();
  cout << endl;
  cout << "Inorder traversal: ";
  T.inorder();
  return 0;
}