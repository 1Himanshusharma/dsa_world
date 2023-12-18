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

int main(){
  create();
  
}