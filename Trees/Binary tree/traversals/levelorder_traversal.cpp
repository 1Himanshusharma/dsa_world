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
  public:
  BT(){
    root = NULL;
  }
  void create(){
    queue<Node *> q;
    cout << "Please enter the root element value: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    q.push(root);
    while (!q.empty()){
      Node *current_node =  q.front();
      q.pop();
      int key;
      cout << "Enter the value of left child: " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Enter the value of right child: " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        current_node->rchild = new Node(key);
        q.push(current_node->rchild);
      }
    }
  }
 void levelorder() {
    queue<Node *> q;
    q.push(root);
    
    while (!q.empty()) {
        Node *current_node = q.front();
        q.pop();
        cout << current_node->data << " ";

        if (current_node->lchild != NULL) {
            q.push(current_node->lchild);
        }
        if (current_node->rchild != NULL) {
            q.push(current_node->rchild);
        }
    }
}

};
int main(){
  BT t;
  t.create();
  cout << "The levelroder traversal";
  t.levelorder();

}