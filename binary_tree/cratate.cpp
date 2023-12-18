#include<iostream>
#include<queue>
using namespace std;


class Node{
  public:
  int data;
  Node *l_child;
  Node *r_child;

  Node(int data){
    this->data = data;
    this->l_child = NULL;
    this->r_child = NULL;
  }
};

Node *create(){
  cout << "enter the value: ";
  int data;
  cin >> data;
  if (data == -1){
    return NULL;
  }

  Node *root = new Node(data);
  cout << "left child: " << root->data << " "; 
  root->l_child = create();
  cout << "right child: "<< root->data << " ";
  root->r_child = create();
  return root;
}

void preorder(Node *root){
  //base condition
  if (root==NULL){
    return;
  }
  // follow NLR 
  cout << root->data << " ";
  preorder(root->l_child);
  preorder(root->r_child);
}
void postorder(Node *root){
  //base condition
  if (root== NULL){
    return;
  }
  // follow LRN
  postorder(root->l_child);
  postorder(root->r_child);
  cout << root->data << " ";
}

void inorder(Node *root){
  //base condition
  if (root == NULL){
    return;
  }
  inorder(root->l_child);
  cout << root->data << " ";
  inorder(root->r_child);
}

// level order
void levelorder(Node *root){
  queue<Node*> q;
  q.push(root);

  while (!q.empty()){
    Node *front = q.front();
    cout << front->data << " ";
    if (front->l_child){
      q.push(front->l_child);
    }
    if (front->r_child){
      q.push(front->r_child);
    }
    q.pop();
  }
  

}

int main(){
  Node *root = create();
  cout << "The preorder traversal: ";
  preorder(root);
  cout << endl;
  cout << "The postorder traversal: ";
  postorder(root);
  cout << endl;
  cout << "The inorder traversal: ";
  inorder(root);
  cout << endl;
  cout << "The level order traversal: ";
  levelorder(root);
}