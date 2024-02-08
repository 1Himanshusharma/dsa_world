#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
  int data;
  Node *lchild;
  Node *rchild;
  
  Node(int key) {
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};

class BT {
private:
  Node *root;

  void inorder(Node *p) {
    if (p) {
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  void leftNode(Node *p){
    if (p== NULL){
      return;
    }
    if (p->lchild == NULL && p->rchild == NULL){
      return;
    }
    cout << p->data << " ";
    if (p->lchild != NULL){
      leftNode(p->lchild);
    }
    else{
      leftNode(p->rchild);
    }
  }
  void rightNode(Node *p){
    if (p== NULL){
      return;
    }
    if (p->lchild != NULL && p->rchild != NULL){
      return;
    }
    cout << p->data << " ";
    if (p->rchild != NULL){
      rightNode(p->rchild);
    }
    else{
      rightNode(p->lchild);
    }
  }
  void bottomNode(Node *p){
    if (p== NULL){
      return;
    }
    if (p->lchild == NULL && p->rchild == NULL){
      cout << p->data << " ";
    }
    bottomNode(p->lchild);
    bottomNode(p->rchild);
  }

public:
  BT() {
    root = NULL;
  }

  void create() {
    int root_ele;
    cout << "Please Enter the root element: ";
    cin >> root_ele;

    if (root == NULL) {
      root = new Node(root_ele);
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      Node *current_node = q.front();
      q.pop();

      int key;
      cout << "Please enter the lchild of " << current_node->data << " : ";
      cin >> key;

      if (key != -1) {
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }

      cout << "Please enter the rchild of " << current_node->data << " : ";
      cin >> key;

      if (key != -1) {
        current_node->rchild = new Node(key);
        q.push(current_node->rchild);
      }
    }
  }

  void inorderTraversal() {
    inorder(root);
  }
  void Boundrytraversal(){
    leftNode(root);
    bottomNode(root);
    rightNode(root->rchild);

  }
};

int main() {
  BT t;
  t.create();
  cout << "The boundry traversal: ";
  t.Boundrytraversal();
  return 0;
}
