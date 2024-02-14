#include<iostream>
using namespace std;


int solve(Node *root){
  if (root == NULL){
    return 0;
  }
  // i have two cases that we can include node or not
  //case1 inlcude;
  int withnode = root->data;
  if (root->left){
    withnode += solve(root->left->left);
    withnode += solve(root->left->right);
  }
  if (root->right){
    withnode += solve(root->right->left);
    withnode += solve(root->right->right);
  }

  // case 2 without node
  int withoutnode = solve(root->left) + solve(root->right);
  return max(withnode, withoutnode);
}