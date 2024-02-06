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
  void inorder(Node *temp){
    if (temp){
      inorder(temp->lchild);
      cout << temp->data << " ";
      inorder(temp->rchild);
    }
  }
  void rightview(Node *temp,int level,vector<int>& view) {
    if (temp== NULL){
      return;
    }
    if (level ==  view.size()){
      view.push_back(temp->data);
    }
    rightview(temp->rchild,level+1,view);
    rightview(temp->lchild,level+1,view);
  }

  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root node value: ";
    int root_ele;
    cin >> root_ele;
    // checking whearther the root node is empty or not
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      int key;
      cout << "Please enter the lchild of " << current_node->data << " : ";
      cin >>key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Please enter the rchild of" << current_node->data << " : ";
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


  // code of right view
  void rightview(){
    vector<int> view;
    rightview(root,0,view);

    cout << "The right view: ";
    for (int i = 0;i < view.size();i++){
      cout << view[i] << " ";
    }
  }

};
int main(){
  BT t;
  t.create();
  cout << "The inorder: ";
  t.inorder();
  cout << endl;
  t.rightview();
}