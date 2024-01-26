#include<iostream>
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

Node* insert(Node* p, int key) {
  if (p == NULL) {
    return new Node(key);
  }

  if (key < p->data) {
    p->lchild = insert(p->lchild, key);
  } else if (key > p->data) {
    p->rchild = insert(p->rchild, key);
  }
  // If key is equal to p->data, you may choose to handle it accordingly or ignore it.

  return p; // Return the current node
}

void preorder(Node* p) {
  if (p) {
    preorder(p->lchild);
    cout << p->data << " ";
    preorder(p->rchild);
  }
}

int main() {
  Node* root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 10);
  cout << "PreOrder Traversal of constructed tree is \n";
  preorder(root);
}
