#include<iostream>
#include<queue>
using namespace std;
class Node{
  public:
  int data;
  Node *left;
  Node *right;
  Node(int key){
    this->data = key;
    this->left = NULL;
    this->right = NULL;
  }
};
class BST{
  private:
  Node *root;
  void inorder(Node *temp){
    if (temp){
      inorder(temp->left);
      cout << temp->data <<  " ";
      inorder(temp->right);
    }
  }
  Node *insert(Node *temp,int key){
    // base case 
    // please go at the end where next is null or the node doesnot exits
    // i know that when i reach at leaf or when i go beyond the last node
    if (temp == NULL){
      return new Node(key);
    }
    //now i need to travesse in the tree
    // i know that how to travesre in binary search treee
    if (key < temp->data){
      temp->left = insert(temp->left,key);
    }
    if (key > temp->data){
      temp->right = insert(temp->right,key);

    }
    // now i have attahced the new node at the right post
    return temp;
  }
  public:
  BST(){
    root = NULL;
  }
  void create(){
    cout << "Enter the elements to stop enter -1: ";
    int n;
    while (true){
      cin >> n;
      if (n == -1){
        break;
      }
      root = insert(root,n);
    }
  }
  void inorder(){
    inorder(root);
  }
  Node *getroot(){
    return root;
  }
};
void levelorder(Node *root){
  queue<Node *> q;
  q.push(root);
  while (!q.empty()){
    Node *current_node = q.front(); q.pop();
    cout << current_node->data << " ";
    if (current_node->left){
      q.push(current_node->left);
    }
    if (current_node->right){
      q.push(current_node->right);
    }
  }
  
}


int main(){
  BST t;
  t.create();
  cout << "THe inorder travesrsal: ";
  t.inorder();
  cout << endl;
  Node *root = t.getroot();
  cout << "Levelorder traversal: ";
  levelorder(root);


}