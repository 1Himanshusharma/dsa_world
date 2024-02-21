#include<iostream>
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
class BST{
  private:
  Node *root;
  void inorder(Node *temp){
    if (temp){
      inorder(temp->left);
      cout << temp->data <<  " ";
      inorder(temp->right);
    }
  }
  Node *insert(Node *temp,int key){
    // base case 
    // please go at the end where next is null or the node doesnot exits
    // i know that when i reach at leaf or when i go beyond the last node
    if (temp == NULL){
      return new Node(key);
    }
    //now i need to travesse in the tree
    // i know that how to travesre in binary search treee
    if (key < temp->data){
      temp->left = insert(temp->left,key);
    }
    if (key > temp->data){
      temp->right = insert(temp->right,key);

    }
    // now i have attahced the new node at the right post
    return temp;
  }
  public:
  BST(){
    root = NULL;
  }
  void create(){
    cout << "Enter the elements to stop enter -1: ";
    int n;
    while (true){
      cin >> n;
      if (n == -1){
        break;
      }
      root = insert(root,n);
    }
  }
  void inorder(){
    inorder(root);
  }
  Node *getroot(){
    return root;
  }
};
// if you want to validate bst  the cond is that left side of tree is less than the right side of tree
// how i am suppose to do that i will take range range for if theat number is lies between the range then i  can say taht is bst
// to mai min or max limit lga deta hu

bool validate(Node *root){
  // if root is null then can i say that is valid 
  if (root ==  NULL){
    return true;
  }
  // if i am starrign from the root then check for left and right cild codition
  // if i find those codtition false then i will just return false;
  if (root->left!= NULL && root->left->data > root->data){
    return false;
  }
  if (root->right!= NULL && root->right->data < root->data){
    return false;
  }
  bool left = validate(root->left);
  bool right = validate(root->right);
  if (left && right ){
    return true;
  }
  return false;
} 

int main(){
  BST t;
  t.create();
  cout << "THe inorder travesrsal: ";
  t.inorder();
  Node *root = t.getroot();
  if (validate(root)){
    cout << "\nThe given binary search tree is a valid Binary Search Tree."<<endl;
    }else{
      cout << "\nThe given binary search tree is not a valid Binary Search Tree."<<endl;
    }

}