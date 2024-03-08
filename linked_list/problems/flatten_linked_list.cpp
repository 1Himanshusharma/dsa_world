#include<iostream>
using namespace std;
Node *merge(Node *list1,Node *list2){
  if (list1== NULL){
    return list2;
  }
  if (list2== NULL){
    return list1;
  }
  if (list1->data <= list2->data){
    list1->next = merge(list1->next,list2);
    return list1;
  }
  else{
    list2->next = merge(list1,list2->next);
    return list2;
  }
}


Node *flatten(Node &root){
  if (root== NULL || root->next == NULL){
    return NULL;
  }
  root = merge(root,root->next);
  root->next = flatten(root->next);
  return root;
}