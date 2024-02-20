#include<iostream>
using namespace std;


void BTtoLL(Node *root){
  // base caee
  // when i readch at NULLnode what i need to do
  // nothing
  if (root == NULL){
    return;
  }
  // temperoray store the right subtree
  Node *rightsubtree = root->right;
  BTtoLL(root->left);
  root->right = root->left;
  root->left = NULL;
  
  // i need to find the last of the linked list
  Node *last = root;
  while (last->right){
    last = last->right;
  }
  // call for right subtree flatten call;
  BTtoLL(rightsubtree);
  //  where should i need to connect right subtree
  // simple i can insert those node at the end of linked list
  
  last->right = rightsubtree;
}