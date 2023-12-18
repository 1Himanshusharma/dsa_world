#include<iostream>
using namespace std;


class Node{
  public:
  int data;
  Node *l_child;
  Node *r_child;

  Node(int data){
    this->data = data;
    this->l_child = NULL;
    this->r_child = NULL;
  }
};

Node *create(){
  cout << "enter the value: ";
  int data;
  cin >> data;
  if (data == -1){
    return NULL;
  }

  Node *root = new Node(data);
  cout << "left child: " << root->data << " "; 
  root->l_child = create();
  cout << "right child: "<< root->data << " ";
  root->r_child = create();
  return root;
}

void preorder(Node *root){
  //base condition
  if (root==NULL){
    return;
  }
  // follow NLR 
  cout << root->data << " ";
  preorder(root->l_child);
  preorder(root->r_child);
}
void postorder(Node *root){
  //base condition
  if (root== NULL){
    return;
  }
  // follow LRN
  postorder(root->l_child);
  postorder(root->r_child);
  cout << root->data << " ";
}

void inorder(Node *root){
  //base condition
  if (root == NULL){
    return;
  }
  inorder(root->l_child);
  cout << root->data << " ";
  inorder(root->r_child);
}

int main(){
  Node *root = create();
  cout << "The preorder traversal: ";
  preorder(root);
  cout << endl;
  cout << "The postorder traversal: ";
  postorder(root);
  cout << endl;
  cout << "The inorder traversal: ";
  inorder(root);
}