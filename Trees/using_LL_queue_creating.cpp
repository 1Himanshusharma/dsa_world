#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* lchild;
  Node* rchild;
};
class L_Node{
  public:
  Node* data;
  L_Node* next;
};
class Queue{
  private:
  L_Node *front, *rear;
  public:
  Queue(){
    front = NULL;
    rear = NULL;
  }
  void enqueue(Node  *val){
    // we can use unlimited space
    // so when we say that linked list is full
    // so when i allocate the dynamic memory. and that memory could not be allocated then i can say that linked list is full
    L_Node *new_node = new L_Node;
    if (new_node == NULL){
      cout << "Memory Error! Can't create a new node." << endl;
    }
    else {
      new_node->data = val;
      new_node->next = NULL;
      if (front == NULL){
        front = new_node;
        rear = front;
      }
      else{
        rear->next = new_node;
        rear = new_node;
      }
  }
  }
  Node *dequeue(){
    Node* x = 0;
    if (front == NULL){
      cout << "Error! Empty queue. Can't remove an element from it." <<
      endl;
    }
    else{
      x = front->data;
      L_Node *temp = front;
      front = front->next;
      delete temp;
    }
    return x;
  }

  bool is_full(){
    L_Node *new_node = new L_Node;
    if (new_node == NULL){
      return true;
    }
    return false;
  }
  bool isempty(){
    if (front == NULL){
      return true;
    }
    return false;
  }
  void display(){
    L_Node *ptr;
    ptr = front;
    while(ptr != NULL) {
      cout << ptr->data << " ";
      ptr = ptr->next;
      }
  }

};
class Tree{
  private:
  Node *root;
  void preorder(Node *p){
    if (p){
      cout << p->data << " ";
      preorder(p->lchild);
      preorder(p->rchild);
    }
  }
  void inorder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
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
    int x,y;
    if (p == NULL)return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return (x>y)?(x+1):(y+1);
  }
  int count(Node *p){
    if (p == NULL){
      return 0;
    }
    return count(p->lchild) + count(p->rchild) + 1;
  }
  int leaf_count(Node *p){
    int x,y;
    if ((p->lchild == NULL) && (p->rchild == NULL)){
      return 1;
    }
    if (p == NULL){
      return 0;
    }
    x = leaf_count(p->lchild);
    y = leaf_count(p->rchild);
    
    return x + y;
  }
  public:
  Tree(){
    root = NULL;
  }
  void create(){
    cout << "Enter the root element: ";
    int root_ele;
    Queue q;
    cin >> root_ele;
    root = new Node;
    root->data = root_ele;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
    while (!q.isempty()){
      Node *temp = q.dequeue();
      int key;
      cout << "Enter the left child of the " << temp->data << ": ";
      cin >> key;
      if (key != -1){
        Node *new_node = new Node;
        new_node->data = key;
        new_node->lchild = NULL;
        new_node->rchild = NULL;
        temp->lchild = new_node;
        q.enqueue(new_node);
      }
      cout << "Enter the right child of the "<< temp->data << ": ";
      cin >> key;
      if (key != -1){
        Node *new_node = new Node;
        new_node->data = key;
        new_node->lchild = NULL;
        new_node->rchild = NULL;
        temp->rchild = new_node;
        q.enqueue(new_node);
      }
    }
  }
  void preorder(){
    preorder(root);
  }
  void inorder(){
    inorder(root);
  }
  void postorder(){
    postorder(root);
  }
  int height(){
    return height(root);
  }
  int count(){
    return count(root);
  }
  int leaf_node(){
    return leaf_count(root);
  }

};


int main(){
  cout << "Enter your element \n To stop press -1: ";
  Tree t;
  t.create();
  cout << "\nPreorder traversal :\t";
  t.preorder();
  cout << "\nInorder traversal :\t";
  t.inorder();
  cout << "\nPostorder traversal:\t";
  t.postorder();
  cout << "\nHeight of the tree is :"<< t.height() ;
  cout << "\nNumber of nodes are :"<< t.count() ;
  cout << "\nLeaf node Counts are :"<< t.leaf_node();


}
