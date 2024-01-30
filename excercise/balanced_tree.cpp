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
class BST{
  private:
  Node *root;
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  int height(Node *p){
    if (p == NULL){
      return 0;
    }
    int left_height = height(p->lchild);
    int right_height = height(p->rchild);
    return (left_height > right_height ? left_height + 1 : right_height + 1);
  }
  bool isBalanced(Node *p){
    if (p == NULL){
      return true;
    }// this is postorder
    bool left_subtree = isBalanced(p->lchild);
    bool right_subtree = isBalanced(p->rchild);
    int diff = height(p->lchild) - height(p->rchild);
    bool ans = diff <= 1;
    return ans && left_subtree && right_subtree;
  }
  public:
  BST(){
    root = NULL;
  }
  // yyar mujhe recursion use karna hai
  // per mai ager value pass karunga then mujhe kaise pta chelega ki main right position per hu
  // fhir kya karna hai aisa kro ek node orr pass kar
  void insert(int key){
    if (root == NULL){
      root = new Node(key);
    }
    else{
      Node *p,*q;
      q = NULL;
      p = root;
      while (p){
        q = p;
        if (p->data > key){
          p = p->lchild;
        }
        if (p->data < key){
          p = p->rchild;
        }
      }
      p = new Node(key);
      if (q->data > key){
        q->lchild = p;
      }
      else{
        q->rchild = p;
      }
    }
  }
  void inorder(){
    inorder(root);
  }
};
int main(){
  cout << "PLEASE ENTER THE SIZE OF ARR: ";
  int n;
  cin >> n;
  BST t;
  while (n--){
    int key;
    cin >> key;
    t.insert(key);
  }
  cout << "Inorder traversal: ";
  t.inorder();
}