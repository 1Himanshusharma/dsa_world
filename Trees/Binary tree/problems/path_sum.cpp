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
void path_sum(Node *p,int target,int sum,vector<int> val){
  if (target == sum){
    for (int i = 0;i < val.size();i++){
      cout << val[i] << " ";
    }
  }
  if (!p){
    return;
  }
  sum += p->data;
  val.push_back(p->data);
  path_sum(p->lchild,target,sum,val);
  path_sum(p->rchild,target,sum,val);
  
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