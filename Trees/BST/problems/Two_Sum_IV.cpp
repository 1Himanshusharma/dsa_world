#include<iostream>
#include<vector>
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
  Node *insert(Node *root,int key){
    if (root == NULL){
      return new Node(key);
    }
    if (root->data > key){
      root->left = insert(root->left, key);
    }
    if (root->data < key){
       root->right = insert(root->right,key);
    }
     
    return root;
  }
  void inorder(Node *root){
    if (root){
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
      
    }
  }
  public:
  BST(){
    root = NULL;
  }
  void create(){
    cout << "Please enter the values to stop enter -1: ";
    int n;
    while (true){
      cin >> n;
      if (n== -1){
        break;
      }
      root = insert(root,n);
    }
  }
  void inorder(){
    inorder(root);
  }
  Node *get_root(){
    return root;
  }
};
// is there any why so i can search the desired value in tree
//  yes you can use recursion for that
// but that recursion having o(n) and the time complexity would reach n2 because we are using just brutefore
// instead using brutefore 
// i also know that inorder of bst is sorted
void storeinorder(Node *temp,vector<int>& val){
  if (temp){
    storeinorder(temp->left,val);
    // i wanna store bst element in that vector
    val.push_back(temp->data);
    storeinorder(temp->right,val);
  }
}
bool findtarget(Node* root,int k){
  vector<int> val;
  storeinorder(root,val);
  // finding the target using two pointer appraoch
  int start = 0;
  int end = val.size() - 1;
  while (start < end){
    int sum = val[start] = val[end];
    if (sum == k){
      return true;
    }
    if (sum > k){
      end--;
    }
    if (sum < k){
      start++;
    }

  }
  return true;
}
int main(){
  BST t;
  t.create();
  cout<<findtarget(t.get_root(),7)<<endl;



}