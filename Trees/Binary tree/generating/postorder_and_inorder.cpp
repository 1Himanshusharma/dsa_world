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
// i wanna generate tree using postoder and inorder
// i know the concept behind it

// what is return tyep ---> Node 
// okay a funcation which is returning the Node

//the parameter needing ---> two vector<int> which in postorder and inorder
// for traversing postorder we will need postorderindex
// for  inorder_start and inorder_end  for partationing the inorder
int search(vector<int> inorder,int target){
    for (int i = 0;i < inorder.size();i++){
        if (inorder[i] == target){
            return i;
        }
    }
    return -1;
}
Node *BuildTree(vector<int> postorder,vector<int> inorder,int postorderindex,int inorder_start,int inorder_end,int size){
    // base case
    // out of bound case
    if (postorderindex < 0 || inorder_start > inorder_end){
        return NULL;
    }
    // find element in postorder
    int element = postorder[postorderindex];
    postorderindex--;
    // find that element's postion in inorder
    int inorder_me_element_postion = search(inorder,element);
    // paritioning
    // create root node
    Node *root = new Node(element);
    // i have created the root ndoe'
    root->rchild = BuildTree(postorder,inorder,postorderindex,inorder_start,inorder_me_element_postion-1,size);
    root->lchild = BuildTree(postorder,inorder,postorderindex,inorder_me_element_postion+1,inorder_end,size);
    // i have attached the lchild and rchild of node
    return root;
}
// but there could me mistake while traversing the postorder
// it is just opposite to inorder
void display(Node *root){
    if (root != NULL){
        display(root->lchild);
        cout << root->data << " ";
        display(root->rchild);
    }
}
int main(){
    vector<int> postorder={9,5,3,6,7,8};
    vector<int> inorder={3,6,9,5,7,8};
    cout << "The tree is : \n";
    int size = postorder.size();
    Node* root = BuildTree(postorder,inorder,size-1,0,size-1,size);
    display(root);
}