#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<queue>
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
    cout << "Please enter the values to stop enter -1: ";
    int key;
    while (true){
      cin >>  key;
      if (key == -1){
        return;
      }
      root = insert(root,key);
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
      temp->right = insert(temp->right,key);
    }
    return temp;
  }
  void inorder(){
    Node *node = root;
    stack<Node *> st;
    while (true){
      if (node){
        st.push(node);
        node = node->left;
      }
      else{
        if (st.empty() == true){
          break;
        }
        node = st.top();st.pop();
        cout << node->data << " ";
        node = node->right;
      }
    }
  }
  void preorder(){
    stack<Node *> st;
    Node *node = root;
    st.push(root);
    while (!st.empty()){
      Node *node = st.top(); st.pop();
      cout << node->data << " ";
      if (node->right){
        st.push(node->right);
      }
      if (node->left){
        st.push(node->left);
      }
    }

  }
};

int main(){
  BST t;
  t.create();
  cout << "The inordet travertsal: ";
  t.inorder();
  cout << "The preorder traversal: ";
  t.preorder();
}