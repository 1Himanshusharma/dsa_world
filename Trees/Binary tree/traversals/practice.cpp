#include<iostream>
using namespace std;
#include<queue>
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
  void levelorder(){
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      cout << current_node->data << " ";
      if (current_node->lchild){
        q.push(current_node->lchild);
      }
      if (current_node->rchild){
        q.push(current_node->rchild);
      }
    }
  }
  void levelorderII(){
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      
      int levelsize = q.size();
      for (int i = 0; i< levelsize;i++){
        Node *current_node = q.front(); q.pop();
        cout << current_node->data << " ";
        if (current_node->lchild){
          q.push(current_node->lchild);
        }
        if (current_node->rchild){
          q.push(current_node->rchild);
        }
      }
      cout << endl;
    }
  }
  void topview(){
    queue<pair<Node *,int>> q;
    map<int,int> mp;
    q.push(make_pair(root,0));
    while (!q.empty()){
      auto temp = q.front();
      q.pop();
      Node *current_node = temp.first;
      int level = temp.second;
      if (mp.find(level) == mp.end()){
        mp[level] = current_node->data;
      }
      if (current_node->lchild){
        q.push(make_pair(current_node->lchild, level - 1));
      }
      if (current_node->rchild){
        q.push(make_pair(current_node->rchild, level + 1));
      }
    }
    for (auto i : mp){
      cout << i.second << " ";
    }
  }
};
int main(){
  BT t;
  t.create();
  cout << "Level order traversal: ";
  t.levelorder();
  cout << "Level order traversalII: ";
  t.levelorderII();
  cout << "Top view";
  t.topview();
}