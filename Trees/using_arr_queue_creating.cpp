#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *lchild;
  Node *rchild;
};
class Queue{
  private:
  int size;
  Node **Q;
  int front,rear;
  public:
  public:
  Queue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node*[size];
  }
  ~Queue(){
    delete[] Q;
  }
  bool is_full(){
    if (rear == size - 1){
      return true;
    }
    return false;
  }
  bool is_empty(){
    if (front == rear){
      return true;
    }
    return false;
  }
  void enqueue(Node *p){
    if (is_full()){
      cout << "Queue is full.";
    }
    else{
      rear++;
      Q[rear] = p;
    }
  }
  Node *dequeue(){
    Node *temp = 0;
    if (is_empty()){
      cout << "Queue is empty.";
    }
    else{
      front++;
      temp = Q[front];
    }
    return temp;
  }
};


// now i am gonna create a tree using queue 
//


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

void postorder(Node *p){
    if (p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void inorder(Node *p){
    if (p){
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

  int height(Node *p){
    int x,y;
    if (p == NULL){
      return 0;
    }
    // mai bol rha hu mujhe left me height chaiye
    x = height(p->lchild);
    y = height(p->rchild);
    if ( x > y ) {
      return (x + 1);
    }
    else{
      return (y + 1);
    }
  }
  int count(Node * p){
    int x,y;
    if ( p == NULL){
      return 0;
    }
    //yyar mai buus ek hi case sollve karunga
    // baki recusion karega
    x = count(p->lchild);
    y = count(p->rchild);
    return x + y + 1;
  }
  int leaf_count(Node* p) {
    // Base case: if the node is NULL, it contributes 0 to the leaf count
    if (p == NULL) {
        return 0;
    }

    // If the node is a leaf (both left and right children are NULL), return 1
    if (p->lchild == NULL && p->rchild == NULL) {
        return 1;
    }

    // Recursively count leaf nodes in the left and right subtrees
    int left_count = leaf_count(p->lchild);
    int right_count = leaf_count(p->rchild);

    // Return the sum of leaf nodes in the left and right subtrees
    return left_count + right_count;
}
  public:
  Tree(){
    root = NULL;

  }

   void create() {
        int n;
        cout << "Enter the number of nodes: ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid number of nodes." << endl;
            return;
        }

        Queue q(n);

        // creating an array to store node values
        root = new Node;
        int root_ele;
        cout << "Please enter the root element: ";
        cin >> root_ele;
        root->data = root_ele;
        root->lchild = nullptr;
        root->rchild = nullptr;
        q.enqueue(root);

        while (!q.is_empty()) {
            Node *temp = q.dequeue();
            cout << "Please enter the lchild of " << temp->data << ": ";
            int key;
            cin >> key;
            if (key != -1) {
                Node *new_node = new Node;
                new_node->data = key;
                new_node->lchild = nullptr;
                new_node->rchild = nullptr;
                temp->lchild = new_node;
                q.enqueue(new_node);
            }

            cout << "Please enter the rchild of " << temp->data << ": ";
            cin >> key;
            if (key != -1) {
                Node *new_node = new Node;
                new_node->data = key;
                new_node->lchild = nullptr;
                new_node->rchild = nullptr;
                temp->rchild = new_node;
                q.enqueue(new_node);
            }
        }
    }
  // ALL the traversals
  // i know that ki all traversals ke liye mujhe recursion ki help chaiye hogi
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
  /// okay i want to count all the lead nodes
  // actually leaf node doesnot have any child nodes
  // mai janta hu ki tree me traversal me mujhe crecurrsion chaiye hoga
  int leaf_count(){
    return leaf_count(root);
  }
};

int main(){
  Tree t;
  t.create();
  cout << "Preorder Traversal: ";
  t.preorder();
  cout << endl << "Inorder Traversal: ";
  t.inorder();
  cout << endl << "Postorder Traversal: ";
  t.postorder();
  cout << endl << "Height of tree is :" << t.height() ;
  cout << endl << "Number of nodes are :" << t.count();
  cout << endl << "Number of Leaf Nodes are :" << t.leaf_count();
  

}