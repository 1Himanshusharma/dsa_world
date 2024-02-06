#include<iostream>
#include<queue>
#include<vector>
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
class BT{
  private:
  Node* root;
  void inorder(Node *temp){
    if (temp){
      inorder(temp->lchild);
      cout << temp->data << " ";
      inorder(temp->rchild);
    }
  }
  bool target_path(Node *temp,int target,vector<int>& path){
    if (temp == NULL){
      return false;
    }
    if (temp->data == target){
      return  true;
    }
    bool left_ka_ans = target_path(temp->lchild,target,path);
    bool right_ka_ans = target_path(temp->rchild,target,path);
    if (left_ka_ans  || right_ka_ans) {
      path.push_back(temp->data);
      return true;
    }
    return false;
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root node value: ";
    int roor_ele;
    cin >> roor_ele;
    if (root == NULL){
      root = new Node(roor_ele);
    }
    // pushing that node into queue
    queue<Node *> q;
    q.push(root);
    // iterating using queue
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      int key;
      cout << "Please enter lchild of " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Please enter rchild of " << current_node->data << " : ";
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
  void target_path(int target){
    vector<int> path;
    bool ans = target_path(root,target,path);
    for (int i =0 ;i < path.size();i++){
      cout << path[i] << "<---";
    }
  }
};
int main(){
  BT t;
  t.create();
  cout << "The inorder: ";
  t.inorder();
  int target;
  cout << "please enter target value: ";
  cin >> target;
  cout << "Path to reach the target node is: " << endl;
  t.target_path(target);
}