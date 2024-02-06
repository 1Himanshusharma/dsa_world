#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
  int data;
  Node *lchild;
  Node *rchild;
  Node(int key) {
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};

// Function to search for the index of an element in the inorder array
int search(vector<int> &inorder, int element, int size) {
  for (int i = 0; i < size; ++i) {
    if (inorder[i] == element) {
      return i;
    }
  }
  return -1;  // Element not found, handle this case appropriately in your code
}

Node *generate(vector<int> &preorder, vector<int> &inorder, int &preorderindex, int inorder_start, int inorder_end, int size) {
  // Base case: out of bound
  if (preorderindex >= size || inorder_start > inorder_end) {
    return NULL;
  }

  // Extract the current root value from the preorder array
  int element = preorder[preorderindex];
  preorderindex++;

  // Create a new node with the current root value
  Node *root = new Node(element);

  // Find the position of that node in inorder
  int position_in_inorder = search(inorder, element, size);

  // Recursively build the left and right subtrees
  root->lchild = generate(preorder, inorder, preorderindex, inorder_start, position_in_inorder - 1, size);
  root->rchild = generate(preorder, inorder, preorderindex, position_in_inorder + 1, inorder_end, size);

  // Return the root node
  return root;
}

void display(Node *root) {
  if (root) {
    display(root->lchild);
    cout << root->data << " ";
    display(root->rchild);
  }
}

int main() {
  vector<int> preorder = {2, 8, 9, 3, 5};
  vector<int> inorder = {8, 9, 2, 5, 3};
  int n = preorder.size();
  int preorderindex = 0;
  Node *root = generate(preorder, inorder, preorderindex, 0, n - 1, n);

  cout << "Preorder Traversal: \n";
  display(root);

  return 0;
}
