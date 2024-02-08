#include<iostream>
using namespace std;
#include<queue>
class Node{
  public:
  int data;
  Node *lchild;
  Noede *rchild;
  Node(int key){
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
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
    int root_ele;
    cout << "Please Enter the root element: ";
    cin >> root_ele;
    if (root == NULL){
      root = new Node(key);
    }
    q.push(root);
    

  }

}