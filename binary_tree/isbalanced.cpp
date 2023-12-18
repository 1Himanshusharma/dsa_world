#include<iostream>
using namespace std;
// these are funcation implementation only


int height(Node* root){
  if (root == NULL){
    return 0;
  }
  int x = height(root->l_child);
  int y = height(root->r_child);
  return max(x,y) + 1;
}

bool isbalanced(Node* root){
  if (root == NULL){
    return true;
  }
  int leftheight = height(root->l_child);
  int rightheight = height(root->rchild);
  int differance = abs(leftheight - rightheight);
  
  bool curr_bal = (differance <= 1);

  bool l_child_bal = isbalanced(root->left);
  bool r_child_bal = isbalanced(root->right);

  if (curr_bal && l_child_bal && r_child_bal){
    return true;
  }
  else{
    return false;
  }
}