#include<iostream>
using namespace std;
#include<queue>
class Node{
  public:
  int data;
  Node *rchild;
  Node *lchild;
  Node(int key){
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};
class BT{
  private:
  Node* root;
  // Function to create a new node.
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root value: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *temp = q.front();
      q.pop();
      int key;
      cout << "Please enter the left child of : " << temp->data << " : ";
      cin >> key;
      if (key != -1){
        temp->lchild = new Node(key);
        q.push(temp->lchild);
      }
      cout << "please enter the right child of : " << temp->data << " : ";
      cin >> key;
      if (key != -1){
        temp->rchild = new Node(key);
        q.push(temp->rchild);
      }
    }
  }
  void inorder(){
    inorder(root);
  }
  Node *get_root(){
    return  root;
  }
};
Node *LCA(Node *root,int p,int q){
  if (root == NULL){
    return NULL;
  }
  if (root->data == p){
    return root;
  }
  if (root->data == q){
    return root;
  }
  Node *left_ki_node = LCA(root->lchild,p,q);
  Node *right_ki_node = LCA(root->rchild,p,q);
  // aab mai check karunga ki on which path from both of side node in returning
  if (left_ki_node== NULL && right_ki_node == NULL){
    return NULL;
  }
  else if (left_ki_node == NULL  && right_ki_node != NULL){
    return right_ki_node;
  }
  else if (left_ki_node != NULL && right_ki_node == NULL){
    return left_ki_node;
  }
  else{
    // returning the current node where left_ki_node and right_ki_node dono NULL nahi hai

    return root;
  }
}
// Node *kth_Ancestor(Node *root,int target,int& k){
//   // base case kya hoga
//   // jab root ki value NULL hai tab mai NULL return kar rha hu
//   if (root == NULL){
//     return NULL;
//   }
//   if (root->data == target){
//     return  root;
//   }
//   if (k == 0){
//     return root;
//   }
//   Node *left_ki_node = kth_Ancestor(root->lchild,target,k);
//   Node *right_ki_node = kth_Ancestor(root->rchild,target,k);
//   if (left_ki_node == NULL && left_ki_node == NULL){
//     return NULL;
//   }
//   if (left_ki_node != NULL || right_ki_node != NULL){
//     k--;
//     return root;
//   }
//   else {
//     return root;
//   }
// }
// okay dobara karta hu
// int kth_Ancestor(Node *root,int target,int& k){
//   if  (root==NULL) return -1;
//   if (root->data == target){
//     return target;
//   }
//   if (k == 0){
//     return root->data;
//   }
//   int left_ka_ans = kth_Ancestor(root->lchild,target,k);
//   int right_ka_ans = kth_Ancestor(root->rchild,target,k);
//   if (left_ka_ans == -1 && right_ka_ans == -1){
//     return -1;
//   }
//   if (left_ka_ans!=-1){
//     k=k-1;
//     return left_ka_ans;
//   }else{
//     return right_ka_ans;
//   }

// }
// okay i wil try one more
// with basic approch
bool kth_Ancestor(Node *temp,int target,int& k){
  if (temp == NULL){
    return false;
  }
  if (temp->data == target){
    return true;
  }
  bool left_ka_ans = kth_Ancestor(temp->lchild,target,k);
  bool right_ka_ans = kth_Ancestor(temp->rchild,target,k);
  if (k == 0){
    cout << temp->data << endl;
    return true;
  }
  if (left_ka_ans || right_ka_ans){
    k--;
    return true;
  }
  return false;
}
int main(){
  BT t;
  t.create();
  cout << "The inorder: ";
  t.inorder();
  int p=40, q=90;
  Node *root = t.get_root();
  cout<<"The LCA of nodes with data "<<p<<" and "<<q;
  Node *ans = LCA(root,p,q);
  cout<<" is : "<<ans->data<<endl;

  int k;
  cout << "Please enter the kth value to find  kth ancestor: ";
  cin >> k;
  bool k_node = kth_Ancestor(root,80,k);
  cout << "\nKth Ancestor of node with data 80 is : "<<k_node<<endl;

}