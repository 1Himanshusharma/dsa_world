##include<iostream>
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
  void preorder(){
    // now the ideology behind this is using the stack which is actually work on principle of last in first out
    // that means that when i insert node first it will out after
    // but in preorder i need to go first on left and then right, if i insert the left node first then it will come out after 
    // creating stack
    stack<Node *> st;
    st.push(root);
    Node *node = root;
    // until i should do the operation i am inserting the node into stack just when i am reaching at that node
    // that why iteraration will same like this until the stack is not empty;
    while (!st.emtpy){
      node = st.top();
      st.pop();
      cout << node->data << " ";
      // now focus and think about if i check the conditon of left side first then it will insert first that means first in last out. it will come out at last
      // in order to avoid this problem i need to check conditon for right side first
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
  BT t;
  t.create();
  cout << "The inorder traversal of tree: ";
  t.inorder();
}