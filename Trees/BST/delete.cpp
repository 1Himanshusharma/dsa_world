#include<iostream>
using namespace std;




/*
  one major properties of BST is that it does not contains duplicates.
  that is why we can also use BST for remove duplicates with time complexity of O(height).

*/
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

Node *insert(Node *p,int key){
  if (p == NULL){
    return new Node(key);
  }
  if (key < p->data){
    p->lchild = insert(p->lchild,key);
  }
  else if (key > p->data){
    p->rchild = insert(p->rchild,key);
  }
  return p;
}

int height(Node *root){
  int x,y;
  if (root == NULL){
    return 0;
  }
  x = height(root->lchild);
  y = height(root->rchild);
  return (x > y ? x+1 : y+1);
}


// predecssor bhut hi kaam ki chij hai
// where p is found node's left child
Node *inpre(Node *p){
  while (p && p->rchild){
    p = p -> rchild;
  }
  return p;
}
Node *insuc(Node *p){
  while (p && p->lchild){
    p = p->lchild;
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
Node *deleten(Node *p,int key){
  Node *q;
  
  if (p == NULL){
    return NULL;
  }
  if (p->lchild == NULL && p->rchild == NULL){
    if (p == NULL){
      p = NULL;
    }
    delete p;
    return NULL;
  }
  if (key < p->data){
    p->lchild = deleten(p->lchild,key);
  }
  else if (key > p->data){
    p->rchild = deleten(p->rchild,key);
  }
  else{
    if (height(p->lchild) > height(p->rchild)){
      q = inpre(p->lchild);
      p->data = q->data;
      p->lchild = deleten(p->lchild,q->data);
    }
    else{
      q = insuc(p->rchild);
      p->data = q->data;
      p->rchild = deleten(p->rchild,q->data);
    }
  }
  return p;
}


int main(){
  cout << "Please enter the values and (to stop enter -1): ";
  Node *root = NULL;
  while (true){
    int key;
    cin >> key;
    if (key == -1){
      break;
    }
    root = insert(root,key);
  }
  cout << "The tree is: \n";
  inorder(root);


  // delete node
  cout << "\n\nPlease enter a value to be deleted from the tree: ";
  int delKey;
  cin >> delKey;
  root = deleten(root,delKey);
  cout << "\nThe modified tree after deletion of "<< delKey <<" is : \n";
  inorder(root);




}