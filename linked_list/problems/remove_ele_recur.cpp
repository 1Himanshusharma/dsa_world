#include<iostream>
using namespace std;


void remove(Node *prev,Node *head,int val){
  //base conditon
  if (head == NULL){
    return;
  }
  if (head->val == val){
    Node *temp = head;
    if (prev == NULL){
      head = head->next;
    }
    else{
      prev->next = head->next;
    }
    remove(prev,head,val);
  }
  else{
    remove(prev,head->next,val);
  }
}