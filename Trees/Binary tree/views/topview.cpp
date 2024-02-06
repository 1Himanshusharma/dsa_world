#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
  int data;
  Node *lchild;
  Node *rchild;
  Node(int key){
    this->data = key;
    this->rchild = NULL;
    this->lchild = NULL;
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
    root =  NULL;
  }
  void create(){
    cout << "Please enter the root element node: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
      Node *current_node = q.front();
      q.pop();
      int key;
      cout << "please enter the lchild of " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "please enter the rchild of " << current_node->data << " : ";
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
  void topview(){
    // i will create my level with the intituatioin of going left side decrase in level and going right side increase in lvel
    map<int,int> view;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while (!q.empty()){
      pair<Node *,int> temp = q.front();
      q.pop();
      Node *current_node = temp.first;
      int level = temp.second;
      // yaar mai mai kya karunga ki view me jo pheli baar add ho rha whi add karunga orr koi add nahi karunga 
      // aab mai check kar rha hu map me
      if (view.find(level)==view.end()){
        // iska matalab hai ki wo level per koi element store nahi hai
        view[level] = current_node->data;
      }
      if (current_node->lchild != NULL){
        q.push(make_pair(current_node->lchild,level-1));
      }
      if (current_node->rchild != NULL){
        q.push(make_pair(current_node->rchild,level+1));
      }
    }
    for (auto i:view){
      cout << i.second << " ";
      }
  }
};
int main(){
  BT t;
  t.create();
  cout << "The inorder: ";
  t.inorder();
  cout << endl;
  cout << "Top View of the tree :";
  t.topview();
 }