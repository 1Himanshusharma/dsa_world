#include<iostream>
using namespace std;
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
void convert(Node *root,Node*& head){
  if (root == NULL)return;
  // i will be using RNL this time 
  // so go to the right size
  convert(root->right,head);
  // now i am the right most node
  // now i need to connect  my right child to my parent
  root->right = head;
  if (head != NULL){
    head->left = root;
  }
  // i am doing operation using head not the roots
  convert(root->left,head);

}

int main(){
  BST t;
  t.create();
  cout << "THe inorder traversal: ";
  t.inorder();
}