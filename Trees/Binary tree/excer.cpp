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
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data  << " ";
      inorder(p->rchild);
    }
  }
  int height(Node *temp){
    if (temp == NULL){
      return 0;
    }
    int left_ki_height = height(temp->lchild);
    int right_ki_height = height(temp->rchild);
    // jo inn dono me max hai whii usji height hogi
    return max(left_ki_height,right_ki_height)+1;
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root Node: ";
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
      cout << "Please enter the left child of " << current_node->data << " : ";
      int key;
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Please enter the right child of " << current_node->data << " : ";
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
    Node *temp = root;
    queue<Node *> q;
    q.push(root);
    // aab mene root node ko queue me store kra diya
    /// why we are using queue
    // you can understand that whenever you are at between of tree
    // now think which node is coming first orr which is coming last
    // you will get to know that first node is using first or last node is using at last
    // which data structure is having that properties simple queue
    //that is why i am using quque
    
    while (!q.empty()){
      Node *current_node = q.front();
      q.pop();
      cout << current_node << " ";
      if (current_node->lchild != NULL){
        q.push(current_node->lchild);
      }
      if (current_node->rchild != NULL){
        q.push(current_node->rchild);
      }
    }
  }
  
};

int main(){
  BT t;
  t.create();
  cout << "Please enter the kth value: ";
  int k;
  cin >> k;
}
