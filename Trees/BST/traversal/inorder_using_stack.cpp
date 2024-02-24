#include<iostream>
using namespace std;
#include<stack>
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
      temp->left = insert(temp->left,key);
    }
    if (temp->data < key){
      temp->right = insert(temp->right,key);
    }
    return temp;
  }
  void inorder(){
    Node *temp = root;
    stack<Node *> st;
    while (true){
      if (temp){
        st.push(temp);
        temp = temp->left;
      }
      // i just have to print just before moving to right side

      else{
        if (st.empty())break;
        temp = st.top();st.pop();
        cout << temp->data << " ";
        temp = temp->right;
      }
    }
  }
};
int main(){
  BST t;
  t.create();
  cout << "The inorder traversal: ";
  t.inorder();
}