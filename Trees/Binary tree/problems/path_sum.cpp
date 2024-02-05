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
  void inorder(Node *temp){
    if (temp){
      inorder(temp->lchild);
      cout << temp->data << " ";
      inorder(temp->rchild);
    }
  }
  public:
  BT(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the root element: ";
    int root_ele;
    cin >> root_ele;
    // i will check if  root is equal to NULL;
    if (root == NULL){
      root = new Node(root_ele);
    }
    // i will create a queue;
    queue<Node *> q;
    // now i will push root node into the queue;
    q.push(root);
    // i will iterate until the queue element's child is not covered
    while (!q.empty()){
      Node *temp = q.front();
      q.pop();
      cout << "Enter the left node of " << temp->data << " : ";
      int key;
      cin >> key;
      // to avoid inserting -1
      if (key != -1){
        temp->lchild = new Node(key);
        q.push(temp->lchild);

      }
      cout << "Enter the right node of " << temp->data << " : ";
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
  Node *getroot(){
    return root;
  }
};
// there are few error try it on your own
bool path_sum(Node * temp,int sum,int target){
  // mujhe sum nikalna hai]
  // to mai leaf node oer
  if (temp == NULL){
    return false;
  }
  sum += temp->data;
  // i will reach at leaf node then i will check whather the sum is equal to target or not
  if (root->lchild == NULL && root->rchild == NULL){
    if (sum == target){
      return true;
    }
    else{
      return false;
    }
  }
  bool left_ka_answer = path_sum(root->lchild,sum,target);
  bool right_ka_answer = path_sum(root->rchild,sum,target);
}

int main(){
  BT b;
  b.create();
  cout<<"Inorder traversal: \n";
  b.inorder();

  cout << "Enter the target value: ";
  int t;
  cin >> t;

  Node *root = b.getroot();


}