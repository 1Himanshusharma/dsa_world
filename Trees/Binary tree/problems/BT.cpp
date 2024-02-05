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
    // i have three option i wil checking one by one
    int left_subtree_ka_result = diameter(temp->lchild);
    int right_subtree_ka_result = diameter(temp->rchild);
    // now i will calculate the height of tree
    int left_wale_ki_height = height(temp->lchild);
    int right_wale_ki_height = height(temp->rchild);
    int current_node_ki_hight = left_wale_ki_height + right_wale_ki_height;
    //   Now i will check which result is better to return
    // i will check 3 of them condition whether which one of them give the maximum value;
    return max(left_wale_ki_height,max(right_wale_ki_height,current_node_ki_hight));

  }
  
  public:
  BT(){
    root = NULL;
  }
  void create() {
    cout << "Please enter the root node: ";
    int root_ele;
    cin >> root_ele;
    
    if (root == NULL) {
        root = new Node(root_ele);
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();

        int lchild_key, rchild_key;

        cout << "Please enter the value of left child for " << node->data << ": ";
        cin >> lchild_key;

        if (lchild_key != -1) {
            node->lchild = new Node(lchild_key);
            q.push(node->lchild);
        }

        cout << "Please enter the value of right child for " << node->data << ": ";
        cin >> rchild_key;

        if (rchild_key != -1) {
            node->rchild = new Node(rchild_key);
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
      q.pop();
      if (temp == NULL){
        cout << endl;
        if (!q.empty()){
          q.push(NULL);
        }
      }
      else{
      
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
int main() {
    BT tree;
    tree.create();

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder();
    cout << endl;

    cout << "Height of the tree: " << tree.height() << endl;

    cout << "Diameter of the tree: " << tree.diameter() << endl;

    cout << "Level Order Traversal: ";
    tree.levelorder();
    cout << endl;

    cout << "Level Order Traversal II: " << endl;
    tree.levelorderII();

    return 0;
}