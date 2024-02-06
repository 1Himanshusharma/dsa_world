#include<iostream>
using namespace std;
#include<queue>
#include<vector>

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
  void inorder(Node *temp){
    if (temp){
      inorder(temp->lchild);
      cout << temp->data << " ";
      inorder(temp->rchild);
    }
  }
  void leftview(Node *temp,int level,vector<int>& left_view){
    if (temp == NULL){
      return;
    }
    if (level == left_view.size()){
      left_view.push_back(temp->data);
    }
    leftview(temp->lchild,level+1,left_view);
    leftview(temp->rchild,level+1,left_view);
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root node elment: ";
    int root_ele;
    cin >> root_ele;
    // i will wheather the root node is null or not null if null then i will allocate memory to the root node;
    if (root == NULL){
      root = new Node(root_ele);
    }
    // i am going to insert root into queue
    queue<Node *> q;
    q.push(root);

    // queue is use for interating
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      cout << "Please enter the lchild of " << current_node->data << " : ";
      int key;
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Please enter the rchild of " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        current_node->rchild = new Node(key);
        q.push(current_node->rchild);
      }
    }
  }
  void inorder(){
    inorder(root);
  }





  //left view of a tree: 
  // i know the properties of the level order that is why it si easy to understand
  void leftview(){
    vector<int> left_view;
    int level;
    leftview(root,0,left_view);

    cout << "printing the left view: ";
    for (int i = 0;i < left_view.size();i++){
      cout << left_view[i] << " ";
    }
  }




};
int main(){
  BT t;
  t.create();
  cout << "the inorder : ";
  t.inorder();
  cout << "Printing left view: ";
  t.leftview();
}