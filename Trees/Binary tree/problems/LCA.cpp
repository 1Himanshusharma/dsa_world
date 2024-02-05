#include<iostream>
using namespace std;
#include<queue>
class Node{
  public:
  int data;
  Node *rchild;
  Node *lchild;
  Node(int key){
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};
class BT{
  private:
  Node* root;
  // Function to create a new node.
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root value: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *temp = q.front();
      q.pop();
      int key;
      cout << "Please enter the left child of : " << temp->data << " : ";
      cin >> key;
      if (key != -1){
        temp->lchild = new Node(key);
        q.push(temp->lchild);
      }
      cout << "please enter the right child of : " << temp->data << " : ";
      cin >> key;
      if (key != -1){
        temp->rchild = new Node(key);
        q.push(temp->rchild);
      }
    }
  }
  void inorder(){
    inorder(root);
  }
  Node *get_root(){
    return  root;
  }
};
Node *LCA(Node *root,Node* p,Node* q){
  if (root == NULL){
    return NULL;
  }
  if (root == p){
    return p;
  }
  if (root = q){
    return q;
  }
  Node *left_ka_ans = LCA(root->lchild,p,q);
  Node *right_ka_ans = LCA(root->rchild,p,q);
  // now i got the answer but
  // i need the print the node on which node return is not NULL
  if (left_ka_ans == NULL && right_ka_ans == NULL){
    return NULL;
  }
  else if (left_ka_ans == NULL && right_ka_ans != NULL){
    return right_ka_ans;
  }
  else if (left_ka_ans != NULL && right_ka_ans == NULL){
    return left_ka_ans;
  }
  else{
    // ye wo wala node jha per return statement dono NULL nahi hai
    return root;
  }
  
}
int main(){
  BT t;
  t.create();
  cout << "The inorder: ";
  t.inorder();
}