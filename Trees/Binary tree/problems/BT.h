#include<queue>
using namespace std;
#include<iostream>
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
  void preorder(Node *p){
    if (p){
      cout << p->data << " ";
      preorder(p->lchild);
      preorder(p->rchild);
    }
  }
  void postorder(Node *p){
    if (p){
      postorder(p->lchild);
      postorder(p->rchild);
      cout << p->data << " ";
    }
  }
  int height(Node *p){
    if (p == NULL){
      return 0;
    }
    int left_ki_height = height(p->lchild);
    int right_ki_height = height(p->rchild);
    return max(left_ki_height,right_ki_height)+1;
  }
  int diameter(Node *temp){
    // okay look for base case
    if (temp == NULL){
      return 0;
    }
    // find the height of left and right subtree
    int lHeight = height(temp -> lchild);
    int rHeight = height(temp -> rchild);
    // now calculate the diameter using the above two values.
    int diam = lHeight + rHeight;
    /* Now check which side is heavier,
    then recur on that side */
    diam = max(diam , max(diameter(temp->lchild) , diameter(temp->rchild)));
    return diam;
  }
  
  public:
  BT(){
    root == NULL;
  }
  void create(){
    cout << "Please enter the root node: ";
    int root_ele;
    cin >> root_ele;
    if (root == NULL){
      root = new Node(root_ele);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *node = q.front();
      q.pop();
      cout << "Please enter the value of  lchild: " << node->data;
      int key;
      cin >> key;
      if (key != -1){
        node->lchild = new Node(key);
        q.push(node->lchild);
      }
      cout << "Please enter the value of rchild: "<< node->data;
      cin >> key;
      if (key != -1){
        node->rchild = new Node(key);
        q.push(node->rchild);
      }
    }
  }
  void inorder(){
    inorder(root);
  }
  void preorder(){
    preorder(root);
  }
  void postorder(){
    postorder(root);
  }
  int height(){
    return height(root);
  }
  void levelorder(){
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
      Node *temp = q.front();
      q.pop();
      cout << temp->data << " ";
      if (temp->lchild != NULL){
        q.push(temp->lchild);
      }
      if (temp->rchild != NULL){
        q.push(temp->rchild);
      }
    }
  }
  void levelorderII(){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
      Node *temp = q.front();
      if (temp == NULL){
        cout << endl;
        q.push(NULL);
      }
      else{
      q.pop();
      cout << temp->data << " ";
      if (temp->lchild != NULL){
        q.push(temp->lchild);
      }
      if (temp->rchild != NULL){
        q.push(temp->rchild);
      }
      }
    }
  }
  int diameter(){
    return diameter(root);
  }
};