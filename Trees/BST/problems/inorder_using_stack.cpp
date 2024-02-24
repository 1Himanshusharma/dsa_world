#include<iostream>
#include<stack>
#include<queue>
#include<vector>
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
  public:
  BST(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the elements to stop enter -1: ";
    int key;
    while (true){
      cin >> key;
      if (key == -1){
        break;
      }
      root = insert(root,key);
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
  Node *get_root(){
    return root;
  }
};
void inorder(Node *temp){
  stack<Node *> st;
  Node *node = temp;
  vector<int> inorder;
  while (true){
    if (node != NULL){
      st.push(node);
      node = node->left;
    }
    else{
      if (st.empty()) break;
      node = st.top();
      st.pop();
      inorder.push_back(node->data);
      node = node->right;
    }
  }
  for (int i = 0;i < inorder.size();i++){
    cout << inorder[i]  << " ";
  }

}

int main(){
  BST t;
  t.create();
  cout << "The inorder teraversal is: ";
  t.inorder();
  Node *root = t.get_root();

}