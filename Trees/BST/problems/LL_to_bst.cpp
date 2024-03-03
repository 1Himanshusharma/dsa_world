


ListNode *findmid(ListNode *head){
  // first we will find the mid of the linked list;
  if (head == NULL){
    return NULL;
  }
  ListNode *slow = head;
  ListNode *fast = head;
  ListNode *pre = NULL;
  while (fast && fast->next){
    pre = slow;
    slow = slow->next;
    fast = fast->next;
    if (fast && fast->next){
      fast = fast->next;
    }

  }
  // unlinking process of linked list
  if (pre != NULL){
    pre->next = NULL;
  }
  return slow;
}

TreeNode *SortedListBst(LinkNode *head){
  if (head == NULL){
    return NULL;
  }
  // if head is nulll then i will simply return null 
  // mujhe ek case solve karna hai
  // mujhe mid chaiye or mai usko root bna dunga

  // but there is a special case that you need to understand *********** 
  // this case is leading infinte recursion that you need to understand
  // because wheneve we are passinf head to funcation then calling mid funcation it is returning head again 
  // them again passing head and then mid will return head again 
  // so this will lead to address sanatizer because predefined statck memory has been fulled
  if (head ->next == NULL){
    return new TreeNode(head->val);
  }

  // finding the mid to linked list
  ListNode *mid = findmid(head);

  //creating new root node
  TreeNode *root = new TreeNode(mid->val);

  // solve one case
  root->left = SortedListBst(head);
  root->right = SortedListBst(mid->next);
  return root;
}