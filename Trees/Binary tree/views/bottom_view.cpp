#include<iostream>
using namespace std;
#include<vector>
#include<map>
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
      Node *current_node = q.front();
      q.pop();
      int key;
      cout << "Please enter the lchild value of " << current_node -> data << ": ";
      cin >>key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Please enter the rchild value of " << current_node -> data <<": ";
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
  void Buttom_view(){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while (!q.empty()){
      pair<Node*,int> temp = q.front();
      q.pop();
      Node *current_node = temp.first;
      int level = temp.second;
      // jo last me value bacti hai wo update ho jayeigi
      mp[level] = current_node->data;
      if (current_node->lchild != NULL){
        q.push(make_pair(current_node->lchild,level-1));
      }
      if (current_node->rchild != NULL){
        q.push(make_pair(current_node->rchild,level+1));
      }
    }
    cout << "The buttom view: ";
    for (auto i : mp){
      cout << i.second << " ";

    }
  }
};
int main(){
  BT t;
  t.create();
  cout << "The inorder : ";
  t.inorder();
  t.Buttom_view();
}