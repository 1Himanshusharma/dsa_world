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
  public:
  Node* root;
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
  int height(Node *temp){
    if (!temp){
      return 0;
    }
    int left_height = height(temp->lchild);
    int right_height = height(temp->rchild);
    return (left_height > right_height ? left_height+1 : right_height+1);
  }
  public:
  void create(){
    queue<Node *> q;
    cout << "Please enter the root Node value: ";
    int t;
    cin >> t;
    root = new Node(t);
    q.push(root);
    
    while (!q.empty()){
      Node *temp = q.front();
      q.pop();
      cout << "Please enter left child of " << temp->data <<  ": ";
      int key;
      cin >> key;
      if (key != -1){
        Node *new_node = new Node(key);
        temp->lchild = new_node;
        q.push(new_node);
      }
      cout << "Enter the right child of :"<< temp->data <<": ";
      cin >> key;
      if (key != -1){
        Node *new_node = new Node(key);
        temp->rchild = new_node;
        q.push(new_node);
      }
    }
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
  int height(){
    return height(root);
  }
  Node *inpre(Node *temp){
    while (temp && temp->rchild){
      temp = temp->rchild;
    }
    return temp;
  }
  Node *insucc(Node *temp){
    while (temp && temp->lchild){
      temp = temp->lchild;
    }
    return temp;
  }
  bool balanced(Node *temp);
};
bool BT::balanced(Node *temp){
  if (temp == NULL){
    return true;
  }
  int left_height = height(temp->lchild);
  int right_height = height(temp->rchild);
  int diff = abs(left_height - right_height);
  bool ans = (diff <= 1 );
  return ans; 
}

int main(){
  cout << "Please enter the values(to stop press -1): ";
  BT t;
  t.create();
  cout << endl << "Inorder Traversal: ";
  t.inorder();
  cout << endl << "Preorder Traversal: ";
  t.preorder();
  cout << endl << "Height of tree is :"<<t.height() ;
  //Checking whether the binary tree is balanced or not
  if (t.balanced(t.root)) {
    cout << "\nThe Binary Tree is Balanced.";
    } else {
      cout << "\nThe Binary Tree is Not Balanced.";}

}