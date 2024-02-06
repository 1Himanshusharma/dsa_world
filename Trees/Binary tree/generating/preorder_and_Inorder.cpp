#include<iostream>
#include<queue>
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
    cout << "Please enter root node value: ";
    int root_ele;
    cin >> root_ele;
    queue<Node *> q;
    if (root == NULL){
      root = new Node(root_ele);
    }
    q.push(root);
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      int key;
      cout << "Please enter the lchild of " << current_node->data << " : ";
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

};
int search(vector<int> inorder,target){
  for (int i = 0; i < inorder.size();i++){
    if (inorder[i] == target){
      return i;
    }
  }
}
Node *generate(vector<int> preorder,vector<int> inorder,int preorderindex,int inorder_start,int inorder_end,int size){
  // base case
  // out of bound
  // hum log jha tak traversal karne wale hai
  if (preorderindex > size || inorder_start > inorder_end){
    return NULL;
  }
  int element = preorder[prorderindex];
  preorderindex++;
  // aab mere paas root node hai
  Node *root = new Node(element);
  // find the position of that node in inorder
  // so that we can get the idea of dividing the a
  int position_in_inorder = search(inorder,element);
  // now i got the new position
  
  
}
int main(){
  BT t;
  t.create();
  t.inorder();
}