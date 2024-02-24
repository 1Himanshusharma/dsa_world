#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *left;
  Node *right;
  Node(int key){
    this->data = key;
    this->left = NULL;
    this->right = NULL;
  }
};
class BST{
  private:
  Node *root;
  Node *insert(Node *root,int key){
    if (root == NULL){
      return new Node(key);
    }
    if (root->data > key){
      root->left = insert(root->left, key);
    }
    if (root->data < key){
       root->right = insert(root->right,key);
    }
     
    return root;
  }
  void inorder(Node *root){
    if (root){
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
      
    }
  }
  public:
  BST(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the values to stop enter -1: ";
    int n;
    while (true){
      cin >> n;
      if (n== -1){
        break;
      }
      root = insert(root,n);
    }
  }
  void inorder(){
    inorder(root);
  }
  Node *get_root(){
    return root;
  }
};

Node *pred(Node *root,Node *target){
  Node *pre = NULL;
  Node *curr = root;
  while (curr){
    if (curr->data == target->data){
      curr = curr->left;
    }
    if (curr->data > target->data){
      curr = curr->left;
    }
    if (curr->data < target->data){
      pre = curr;
      curr = curr->right;
    }
  }
  return pre;
}

int main(){
  BST t;
  t.create();
  cout << "THe inorder traversal: ";
  t.inorder();
  Node *root = t.get_root();
  cout << "The inorder predecessor: ";
  Node *pre = pred(root, root);
  cout << pre->data;
}