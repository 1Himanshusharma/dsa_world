
// first thing we dont need to traverse complete three
// because BST has the ablity to determine the path wehere we need to go first
Tr



TreeNode *delete(TreeNode *root,int key){
  // first try to find  that path as we already know path is already defined in BST
  if (root == NULL){
    return NULL;
  }
  if (root->val> key){
    //that means that i need to go left side first
    root->left = delete(root->left,key);
  }
  else if (root->val < key){
    // that means that i need to go to right side of the tree
    root->right = delete(root->right,key);
  }
  else{
    // this is the case where we found that key has been found 
    //then i will chandle the case whose left or right child doesnot exist
    if (root->left == NULL){
      swap(root->val,root->right- > val);
      root->right = delete(root->right,root ->val);
    }
    else if (root->right == NULL){
      swap(root->val,root->left->val);
      root->left= delete(root->left,root->val);
    }
    else{
      TreeNode *pre_node = pre(root->left);
      swap(root->val,pre_node->val);
      root->left = delete(root->left,pre_node->val);
    }

  }
}