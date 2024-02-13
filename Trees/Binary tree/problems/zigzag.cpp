#include<iostream>
using namespace std;
#include<queue>
#include<set>
#include<map>
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
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root node value: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *current_node = q.front(); q.pop();
      cout << "Please Enter the lchild of " << current_node->data << " : ";
      int key;
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Please Enter the rchild of " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        current_node->rchild = new Node(key);
        q.push(current_node->rchild);
      }
    }
  }
  void zigzag(){
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty()){
      int levelsize = q.size();
      bool flag = true;
      vector<int> val(levelsize);
      for (int i = 0;i < levelsize;i++){
        Node *current_node = q.front(); q.pop();
        if (current_node){
          int index = flag ? i : levelsize - i - 1;
          val[index] = current_node->data;
          if (current_node->lchild){
            q.push(current_node->lchild);
          }
          if (current_node->rchild){
            q.push(current_node->rchild);
          }
        }
      }
      ans.push_back(val);
      flag = !flag;
    }
    for (int i = 0 ; i < ans.size(); i++){
      cout << "{ ";
      for (int j = 0;j < ans[i].size();j++){
        cout << ans[i][j] << " ";
      }
      cout <<" }";


    }
  }
};
int main(){
  BT t;
  t.create();
  cout << "zigzag traversal: ";
  t.zigzag();
 
}