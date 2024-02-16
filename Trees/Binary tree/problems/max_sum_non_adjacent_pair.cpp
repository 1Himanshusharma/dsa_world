#include<iostream>
using namespace std;


// pair<int,int> solve(Node *root){
//   if (root){
//     return {0,0};
//   }
//   // now hadle the two cases
//   // 1. root is a leaf node
//   auto left = solve(root->left);
//   auto right = solve(root->right);

//   // i am having pair whcih will store  sum of left subtree and number of nodes in it
//   int sum = root->data;
//   if (left.first == right.first){
//     sum += max(left.second,right.second);
//   }// it means that we are at the same level;
//   else if (left.first > right.first){
//     sum += left.second;
//   }  
//   else {
//     sum += right.second;
//   }
//   return make_pait()
// }


// the pair represent the non adjacent node 
// first element the sum with nodes and other sum with outout node
// why we are doing this 
pair<int,int> solve(Node *root){
  if (root == NULL){
    return {0,0};
  }
  auto left = solve(root->left);
  auto right = solve(root->right);

  int withnode = root->data + left.second + right.second;
  int withoutnode = max(left.first,left.second) + max(right.first,right.second);

  return (withnode,without);
}