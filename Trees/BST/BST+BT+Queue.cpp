#include<iostream>
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
class LNode{
  public:
  int data;
  LNode *next;
  LNode(int key){
    this->data = key;
    this->next = NULL;
  }
};
class Queue{
  private:
  LNode *front,*rear;
  public:
  Queue(){
    front = rear = NULL;
  }
  bool is_full(){
    LNode *new_node = new LNode(1);
    if (new_node == NULL){
      return true;
    }
    return false;
  }
  bool is_empty(){
    if (front == NULL){
      return true;
    }
    return false;
  }
  void enqueue(int key){
    if (is_full()){
      // as we are using linked list queue.
      cout << "Queue is full.";
    }
    else{
      LNode *new_node = new LNode(key);
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
  int dequeue(){
    int temp = 0;
    if (is_empty()){
      cout << "Queue is empty.";
    }
    else{
      temp = front->data;
      front = front->next;
    }
    return temp;
  }
};
// i have completed the code for queue

class BST{
  private:
  Node *root;
  void inorder(Node *temp){
    if (temp){
      inorder(temp->lchild);
      cout << temp->data << " ";
      inorder(temp->rchild);
    }
  }
  void preorder(Node *temp){
    if (temp){
      cout << temp->data << " ";
      preorder(temp->lchild);
      preorder(temp->rchild);
    }
  }
  void postorder(Node *temp){
    if (temp){
      postorder(temp->lchild);
      postorder(temp->rchild);
      cout << temp->data << " ";
    }
  }
  public:
  BST(){
    root = NULL;
  }
  // first i wanna implement the iterative appraoch to insert in Binary search tree .
  void insert(int key){
    //sabse phele check kro ki root node null to nahi hai
    if (root == NULL){
      root = new Node(key);
    }
    else{
      Node *p,*q;
      // as we that we can add only leaf position in BST
      p = root;
      while (p){
        // i will needing that previous node what we have
        q = p;
        if (key< p->data){
          p = p->lchild;
        }
        if (key > p->data){
          p = p->rchild;
        }
        else{
          return;
        }
      }
      p = new Node(key);
      if (key <  q->data){
        q->lchild = p;
      }
      else{
        q->rchild = p;
      }
    }

  }
  bool search(int key){
    if (root == NULL){
      return false;
    }
    // i will iterate through whole tree
    Node *temp = root;
    while (temp){
      if (temp->data = key){
        return true;
      }
      if (temp->data > key){
        temp->lchild;
      }
      if (temp->data < key){
        temp->rchild;
      }
    }
    return false;
  }
  //get root
  Node *get_root(){
    return root;
  }
  // height of binary tree;
  int Height(Node *temp){
    int x,y;
    if (temp== NULL){
      return 0;
    }
    x = Height(temp->lchild);
    y = Height(temp->rchild);
    return (x > y) ? (x+1) : (1 + y);
  }
  // inpre
  Node *inpre(Node *temp){
    // aab mai janta hu mujhe inorder right most node chiaye
    while (temp && temp->rchild!= NULL){
      temp = temp->rchild;
    }
    return temp;
  }
  Node *insucc(Node *temp){
    // aab mujhe inorder me left most node chaiye
    while (temp && temp->lchild!=NULL){
      temp = temp->lchild;
    }
    return temp;
  }
  // Recursive insert
  // recursicvely inserts the element into the Binary Search Tree.
  Node *rinsert(Node *temp,int key){
    // aab jo node paas kiya hai wo root node hai 
    // to mujhe right position per jana hoga
    if (temp == NULL){
      // pta hai jab temp null ho jayega tab hum right positon per honge orr hume wha per node insert karna padega
      return new Node(key);
      // that return node will insert at leaf position
    }
    if (key < temp->data){
      temp->lchild = rinsert(temp->lchild,key);
    }
    if (key > temp->data){
      temp->rchild = rinsert(temp->rchild,key);
    }
    // now i have handle all the cases
    return temp;
  }
  // recusively searching in binary search tree
  bool rsearch(Node* temp, int key){
    // we shall avoid recursion whenever it is not necessary
    if (temp==NULL){
      return false;
    }
    if (temp->data = key){
      return true;
    }
    if (temp->data > key){
      return rsearch(temp->lchild,key);
    }
    if (temp->data < key){
      return rsearch(temp->rchild,key);
    }
    return false;
  }
  // deleting funcation
  // keep in mind that we can delete leaf node in 
  Node *ndelete(Node *temp,int key){
    // dekho 
    if (temp == NULL){
      if (temp == root){
        root = NULL;
      }
      return NULL;
    }
    // Make sure to set pointers to NULL after deleting a node
    if (temp->lchild == NULL && temp->rchild == NULL) {
        delete temp;
        return NULL;
    }
    // go to the right position
    if (key < temp->data){
      temp->lchild = ndelete(temp->lchild,key);
    }
    else if (key > temp->data){
      temp->rchild = ndelete(temp->rchild,key);
    }
    else{
      // that one case when i found the right node
      // mujhe ek indea aaya ki mai usss wale subtee ka inorder travesal karunga jiski height jayada hogi
      // mujhe hight chaiye
      if (Height(temp->lchild) > Height(temp->rchild)){
        // left wale ki height jayada hai tho
        Node *q = inpre(temp->lchild);
        temp->data = q->data;
        // aab mene data replace kar diya but now i have two same nodes
        // so i need to delete the q with q->data
        // so i will do recursion again
        temp->lchild = ndelete(temp->lchild,q->data);
      }
      else{
        Node *q = insucc(temp->rchild);
        temp->data = q->data;
        temp->rchild = ndelete(temp->rchild,q->data);
      }
    }
    return temp;
  }
  void inorder(){
    inorder(root);
  }
  void postorder(){
    postorder(root);
  }
  void preorder(){
    preorder(root);
  }
};
void display(Node *temp){
  if (temp){
    display(temp->lchild);
    cout << temp->data << " ";
    display(temp->rchild);
  }
}
int main(){
  BST t;
  cout << "Please enter the elements (to stop press -1): ";
  while (true){
    int key;
    cin >> key;
    if (key == -1){
      break;
    }
    t.insert(key);
  }
  cout << "\nInorder traversal: ";
  t.inorder();
  cout << "\nPostorder traversal: ";
  t.postorder();
  cout << "\nPreorder traversal: ";
  t.preorder();
  Node *root = t.get_root();
  cout << "\nEnter element to delete: ";
  int del;
  cin >> del;
  root = t.ndelete(root,del);
  if (!root) {
    cout << "\nThe tree is empty now.";
    } else {
      cout << "\nThe modified binary search tree after deletion of "<< del <<" is : \n";
      cout << "Inorder Traversal: ";
      display(root);
      }
}
