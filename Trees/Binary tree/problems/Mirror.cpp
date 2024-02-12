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
  bool mirror(Node *p,Node *q){
    if (!p && !q){
      return true;
    }
    if (p->data == q->data){
      bool left_ka_ans = mirror(p->lchild,q->rchild);
      bool right_ka_ans = mirror(p->rchild,q->lchild);
      return left_ka_ans && right_ka_ans;
    }
    return false;
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
  bool mirror(){
    return mirror(root->left,root->right);
  }
};
int main(){
  BT t;
  t.create();
  cout << "The inorder: ";
  t.inorder();
  cout << "\nDo you want to create a mirror tree? Enter yes/no: ";
  bool res = t.mirror();
  cout << "That is mirror or not: " << res;
}