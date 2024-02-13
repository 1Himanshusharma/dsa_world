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
  void solve(Node *p,vector<int> val){
    if (p == NULL){
      
      return;
    }
    val.push_back(p->data);
    if (!p->lchild && !p->rchild){
      for (int i = 0 ; i < val.size() ; i++){
        cout << val[i] << " ";
      }
      cout << endl;
    }
    
    solve(p->lchild,val);
    solve(p->rchild,val);
  }
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
  void solve(){
    vector<int> val;
    solve(root,val);
  }
};
int main(){
  BT t;
  t.create();
  cout << "root_ to _leaf: ";
  t.solve();

}