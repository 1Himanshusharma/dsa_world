class Solution{
  public:
  Node *connect(Node *root){
    // i need to traverse level wise 
    //that means each level left node first
    // in  case of perfect binary treee
    while (start){
      // i need to travese through level wise linked list
      Node *current_node = start;
      while (current_node){
        if (current_node->left){
          current_node->left->next = current_node->right;
          if (current_node->next){
            if (current_node->next->left){
              current_node->right->next = current_node->next->left;
            }
          }
        }
        current_node = current_node->next;
      }
      start = start->left;
    }
  }
}