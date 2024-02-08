#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
  Node *root;
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  void left_view(Node *p,int level,vector<int>& view){
    if (p== NULL){
      return;
    }
    if (level == view.size()){
      view.push_back(p->data);
    }
    left_view(p->lchild,level+1,view);
    left_view(p->rchild,level+1,view);
  }
  void right_view(Node *p,int level,vector<int>& view){
    if (p == NULL){
      return;
    }
    if (level == view.size()){
      view.push_back(p->data);
    }
    right_view(p->rchild,level+1,view);
    right_view(p->lchild,level+1,view);
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "please enter the root node value: ";
    int root_ele;
    cin >> root_ele;
    if ( root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      int key;
      cout << "Please enter the lchild of " << current_node->data << " : ";
      cin >> key;
      if (key!=-1){
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
  void levelorder(){
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      cout << current_node->data << " ";
      if (current_node->lchild != NULL){
        q.push(current_node->lchild);
      }
      if (current_node->rchild != NULL){
        q.push(current_node->rchild);
      }
    }
  }
  void levelorderII(){
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
  void left_view(){

    vector<int> lview;

    left_view(root,0,lview);

    cout << "The left view: ";
    for (int i = 0; i < lview.size() ; i++){
      cout << lview[i] << " ";
    }

  }
  void right_view(){
    vector<int>  rview;
    right_view(root,0,rview);

    cout << "printing the right view: ";
    for (int i =0 ;i < rview.size();i++){
      cout << rview[i] << " ";
    }
  }
  void top_view(){
    queue<pair<Node *,int>> q;
    q.push(make_pair(root,0));
    map<int,int> mp;
    
    while (!q.empty()){
      pair<Node *,int> temp = q.front();
      q.pop();
      Node *current_node = temp.first;
      int level = temp.second;
      if (mp.find(level) == mp.end()){
        mp[level] = current_node->data;
      }
      if (current_node->lchild != NULL){
        q.push(make_pair(current_node->lchild,level-1));
      }
      if (current_node->rchild != NULL){
        q.push(make_pair(current_node->rchild,level+1));
      }
    }

    cout << "Printing top view: ";
    for (auto i : mp){
      cout << i.second << " ";
    }
  }
  void bottomview(){
    queue<pair<Node *,int>> q;
    q.push(make_pair(root,0));
    map<int,int> mp;
    while (!q.empty()){
      pair<Node *,int> temp = q.front();
      q.pop();
      Node *current_node = temp.first;
      int level = temp.second;
      mp[level] = current_node->data;
      if (current_node->lchild != NULL){
        q.push(make_pair(current_node->lchild,level-1));
      }
      if (current_node->rchild != NULL){
        q.push(make_pair(current_node->rchild,level+1));
      }
    }
    cout << "printing bottomview: ";
    for (auto i : mp){
      cout << i.second << " ";
    }
  }
};
int main(){
  BT t;
  t.create();
  // cout << "THe inorder: ";
  // t.inorder();

  // cout << "THe level order: ";
  // t.levelorder();
  // cout << endl << "the levelorderII : ";
  // t.levelorderII();
  
  // t.left_view();

  // t.right_view();

  // t.top_view();

  t.bottomview();
}