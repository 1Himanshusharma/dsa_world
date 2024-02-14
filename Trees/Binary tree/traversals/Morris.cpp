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
      cout << p->data << " ";
      inorder(p->rchild);
    }
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
      cout << "Please enter the lchild of " << current_node->data < " : ";
      int key;
      cin >> key;
      if (key != -1){
        current_node->lchild = new Node(key);
        q.push(current_node->lchild);
      }
      cout << "Please enter the rchild of " << current_node->data << " : ";
      cin >>key;
      if (key != -1){
        current_node->rchild = new Node(key);
        q.push(current_node->rchild);
      }
    }
  }
  void inorder(){
    inorder(root);
  }
void morris_traversal() {
    Node *standing_root = root;
    
    while (standing_root) {  // Change: Use while (standing_root) instead of while (!standing_root)
        if (standing_root->lchild == NULL) {
            // Process the current node
            // TODO: Add your code to process the current node
            
            standing_root = standing_root->rchild;  // Move to the right child
        } else {
            // Find the in-order predecessor (rightmost node in the left subtree)
            Node *current_node = standing_root->lchild;
            while (current_node->right && current_node->right != standing_root) {
                current_node = current_node->right;
            }

            if (current_node->right == NULL) {
                // Make the threaded link to the current node
                current_node->right = standing_root;
                standing_root = standing_root->lchild;  // Move to the left child
            } else {
                // Remove the threaded link
                current_node->right = NULL;
                
                // Process the current node
                // TODO: Add your code to process the current node
                
                standing_root = standing_root->rchild;  // Move to the right child
            }
        }
    }
}

};
int main(){
  BT t;
  t.create();
  cout << "The inorder Traversal: ";
  t.inorder();

}