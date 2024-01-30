#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* lchild;
  Node* rchild;
  Node(int key){
    this->data =  key;
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
  bool sum_path(Node *p,int target,int sum){
    // mujhe root to leaf jaana hai sum karte huee
    // ager mai leaf node per phuch gya tho
    // to mai check karunga ki sum ki value target ke equal hia ya nahi]
    if (p == NULL){
      return false;
    }
    sum += p->data;
    if (p->lchild == NULL && p->rchild == NULL){
      if (sum == target) {return true;}
      else {return false;}
    }
    bool left_ka_ans = sum_path(root->lchild,target,sum);
    bool right_ka_ans = sum_path(root->rchild,target,sum);
    return left_ka_ans || right_ka_ans;
  }
  public:
  BST(){
    root = NULL;
  }
  void insert(int key){
    if (root == NULL){
      root = new Node(key);
    }
    else{
      Node *p,*q;
      p = root;
      while(p){
        q = p;
        if (p->data > key){
          p = p -> lchild;
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
  bool sum_path(int target){
    return sum_path(root,target);
  }
};
int main(){
  cout << "Please Enter the  number of elements you want to enter:"<< endl;
  int n;
  cin >> n;
  BST t;
  while (n--){
    int key;
    cin >> key;
    t.insert(key);
  }
  cout << "Inorder sum: ";
  t.inorder();

  cout << endl;
  int target;
  cout << "Please enter the target value: ";
  cin >> target;

}