#include<iostream>
#include<queue>
#include<stack>
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
class BT{
  private:
  Node *root;
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root_ele elements: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
      Node *current = q.front();q.pop();
      int key;
      cout << "Please enter the left child of " << current->data << " : ";
      cin >> key;
      if (key != -1){
        current->left = new Node(key);
        q.push(current->left);
      }
      cout << "Plase enter the right child of " << current->data << " : ";
      cin >> key;
      if (key != -1){
        current->right = new Node(key);
        q.push(current->right);
      }
    }
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
  void inorder_using_stack(){
    vector<int> inorder;
    stack<Node *> st;
    Node *temp = root;
    while (true){
      if (temp != NULL){
        st.push(temp);
        temp= temp->left;
      }
      else{
        if (st.empty()) break;
        int ele = st.top();
        st.pop();
        inorder.push(ele);
        temp = temp->right;
      }
    }  
    for (int i =0 ;i < inorder.size(); i++){
      cout << inorder[i] << " ";
    }

  }
};
int main(){
  BT t;
  t.create();
  cout << "The inorder traversal of tree: ";
  t.inorder();
}