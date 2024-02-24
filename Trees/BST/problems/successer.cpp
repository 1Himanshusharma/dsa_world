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
class BST(){
  private:
  Node *root;
  public:
  BST(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the values to stop enter -1: ";
    int n;
    while (true){
      cin >> n;
      if (n == -1){
        break;
      }
      root = insert(root,n);
    }
  }
  Node *insert(Node *temp,int key){
    if (temp == NULL){
      return new Node(key);
    }
    if (temp->data > key){
      temp->left = insert(temp->left, key);
    }
    if (temp->data < key){
      temp->right = insert(temp->right,key);
    }
    return temp;
  }
  void inorder(){
    inorder(root);
  }
  void inorder(Node *temp){
    if (temp){
      inorder(temp->left);
      cout << temp->data << " ";
      inorder(temp->right);
    }
  }
  Node *succ(){
    Node *suc = NULL;
    Node *curr = root;
    while (curr){
      if (curr->data > root->data){
        suc = curr;
        curr = curr->left;
      }
      if (curr->data < root->data){
        curr = curr->right;
      }
      if (curr->data == root->data){
        curr = curr->right;
      }
    }
    return suc;
  }

  
}