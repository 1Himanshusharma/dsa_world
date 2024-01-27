#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *lchild;
  Node *rchild;
  Node(int key){
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};
// where p is represent the last Node
Node *insert(Node *p,int key){
  if (p==NULL){
    return new Node(key);
  }
  if (key < p->data){
    p->lchild = insert(p->lchild,key);
  }
  if (key > p->data){
    p->rchild = insert(p->rchild,key);
  }
  return p;
}
void inorder(Node *p){
  if (p){
    inorder(p->lchild);
    cout << p->data << " ";
    inorder(p->rchild);
  }
}


bool search(Node *p,int key){
  if (p == NULL){
    return false;
  }
  Node *temp = p;
  while (temp){
    if (temp->data == key){
      return true;
    }
    if (key < temp->data){
      temp = temp->lchild;
    }
    if (key > temp->data){
      temp = temp->rchild;
    }
  }
  return false;
}

int main(){
  cout << "Please enter the values and (to stop enter -1): ";
  Node *root = NULL;
  while (true){
    int key;
    cin >> key;
    if (key== -1){
      break;
    }
    root = insert(root,key);
  }
  cout << "\nInorder traversal of constructed tree is: \n";
  inorder(root);
  cout<<endl;
  // Searching for a number in BST.
  int num=5;
  if (search(root,num)){
    cout << "Number " << num << " is present in BST" << endl;
    } else {
      cout << "Number " << num << " is not present in BST" << endl;
    }
}