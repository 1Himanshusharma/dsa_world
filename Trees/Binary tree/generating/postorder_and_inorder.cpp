#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
    
    // Constructor to initialize the Node with data
    Node(int value) : data(value), lchild(NULL), rchild(NULL) {}
};

int search(vector<int> inorder, int instart, int inend, int target) {
    for (int i = instart; i <= inend; i++) {
        if (inorder[i] == target) {
            return i;
        }
    }
    return -1;
}

Node* generate(vector<int> postorder, vector<int> inorder, int& postorderindex, int inorder_start, int inorder_end, int size) {
    // Base case
    if (inorder_start > inorder_end) {
        return NULL;
    }
    
    int element = postorder[postorderindex--];
    Node *root = new Node(element);
    
    int position_in_inorder = search(inorder, inorder_start, inorder_end, element);

    // Recursively construct the right subtree before left subtree
    root->rchild = generate(postorder, inorder, postorderindex, position_in_inorder + 1, inorder_end, size);
    root->lchild = generate(postorder, inorder, postorderindex, inorder_start, position_in_inorder - 1, size);

    return root;
}

void display(Node* root) {
    if (root) {
        display(root->lchild);
        cout << root->data << " ";
        display(root->rchild);
    }
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 3, 20};
    int size = 5;
    int postorderindex = size - 1; // Start from the last index of postorder

    Node* root = generate(postorder, inorder, postorderindex, 0, size - 1, size);
    
    cout << "The constructed tree is : \n";
    display(root);

    return 0;
}
