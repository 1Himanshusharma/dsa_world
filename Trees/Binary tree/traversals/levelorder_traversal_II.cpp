#include<iostream>
using namespace std;
#include<queue>
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
class BT{
  private:
  Node *root;
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root element value: ";
    int root_ele;
    cin >> root_ele;
    queue<Node *> q;
    if (root == NULL){
      root = new Node(root_ele);
    }
    q.push(root);
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      cout << "Enter the lchild of " << current_node->data << " : ";
      int key;
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Enter the rchild of " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        current_node->rchild = new Node(key);
        q.push(current_node->rchild);
      }
    
    }
  }
  void levelorder(){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      if (current_node == NULL){
        cout << endl;
        if (!q.empty()){
          q.push(NULL);
        }
      }
      else{
        cout << current_node->data << " ";
        if (current_node->lchild != NULL){
          q.push(current_node->lchild);
        }
        if (current_node->rchild != NULL){
          q.push(current_node->rchild);
        }
      }
    }
  }
};
int main(){
  BT t;
  t.create();
  cout << "The levelorder: ";
  t.levelorder();
}