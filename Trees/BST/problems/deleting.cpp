#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *left;
  Node *right;
};
class BST{
  private:
  Node *root;
  public:
  BST(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root element to stop enter -1: ";
    int key;
    while (true){
      cin >> key;
      root = new Node(key);
    }
  }
  Node *insert(Node *temp,int key){
    if (temp == NULL){
      return new Node(key);
    }
    if (temp->data > key){
      temp->left = insert(temp->left,key);
    }
    if (temp->data < key){
      temp->right = insert(temp->right, key);
    }
    return temp;
  }
  int height(Node *temp){
    if (temp == NULL){
      return 0;
    }
    return height(temp->left)+ height(temp->right) + 1;
  }
  Node *pred(Node *node){
    while (node && node->right){
      node = node->right;
    }
    return node'
  }
  Node *succ(Node *node){
    while (node && node->left){
      node = node->left;
    }
    return node;
  }
  Node *del(Node *node,int key){
    if (node == NULL){
      if (node == root){
        root = NULL;
      }
      return NULL;
    }
    if (node->left == NULL && node->right == NULL){
      delete node;
      return NULL;
    }
    if (node->data < key){
      node->left = del(node->left,key);
    }
    else if (node->data > key){
      node->right = del(node->right,key);
    }
    else{
      if (height(node->left) < height(node->right)){
        Node *pre = pred(node->left);
        node->data = pre->data;
        node->left = del(node->left,pre->data);
      }
      else{
        Node *sucd = succ(node->right);
        node->data = sucd->data;
        node->right = del(node->right,sucd->data);
      }

    }
    return node;
  }
}