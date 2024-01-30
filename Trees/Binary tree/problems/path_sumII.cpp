#include<iostream>
#include<vector>
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
class BST{
  private:
  Node* root;
  void inoreder(Node *p){
    if (p){
      inorder(p->lchild);
      cout << p->data << " ";
      inorder(p->rchild);
    }
  }
  void path_sum(Node *p,int target,int sum,vector<int> temp,vector<int>& ans){
    if (!p){
      return;
    }//
    // first i will acces sthat element and sum into sum
    // then check whether the current node is a leaf or not. If it's not a
    // then i go to leaf node and check where the sum is equal to target
    sum += p->data;
    temp.push_back(p->data);
    if (p->lchild == NULL  && p->rchild == NULL) {
      if (sum == target){
        ans.push_back(temp);
        return;
      }
      else{
        return;
      }
    }
    // left wale ke liye call  karwana hai
    path_sum(p->lchild,target,sum,temp,ans);
    path_sum(p->rchild,target,sum,temp,ans);
  }
  public:
  void insert(int key){
    if (root == NULL){
      root = new Node(key);
    }
    else{
      Node *p,*q;
      p = root;
      while (p){
        q = p;
        if (p->data > key) p=p->lchuld;
        if (p->data < key) p=p->rchild;
      }
      p = new Node(key);
      if (q->data > key){
        q->lchild = p;
      }
      else{
        q->rchild = p;
      }
    }
  }
  void inorder(){
    inorder(root);
  }
  void path_sum(int target){
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root,target,0,temp,ans);
    for (int i = 0;i< ans.size;i++){
      for (int j = 0;j < ans.size;j++){
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }
}
int main(){
  cout << "please enter the number of elements: ";
  int n;
  BST t;
  cin >> n;
  while (n--){
    int key;
    cin >> key;
    t.insert(key);
  }
  cout << "The inorder tarversal: ";
  t.inorder();

  cout << "Please enter the target value: ";
  int target;
  cin >> target;
  t.path_sum(target);
}