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
  Node *del(Node *temp,int key){
    if (temp == NULL){
      if (temp == root){
        root = NULL;
      }
      return NULL;
    }
    if (temp->left== NULL && temp->right == NULL){
      delete temp;
    }
    if (temp->data > key){
      temp->left  = del(temp->left,key);
    }
    else if (temp->data < key){
      temp->right = del(temp->right,key);
    }else{
      if (height(temp->left) < height(tmemp->right)){
        Node *predeccesor = pred(temp->left);
        temp->data = predeccesor->data;
        temp->left = del(temp->left,predeccesor->data);
      }
      else{
        Node *successor  = succ(temp->right)
        temp->data = successor->data;
        temp->right = del(temp->right,successor->data);
      }
    }
    return temp;

  }
}