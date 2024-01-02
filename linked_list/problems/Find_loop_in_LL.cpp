#include<iostream>
using namespace std;


bool check_loop(Node *head){
  Node *slow = head;
  Node *fast = head;
  while (fast){
    fast = fast->next;
    if (fast->next != NULL){
      fast = fast->next;
      slow = slow->next;
    }
    if (slow == fast){
      return true;
    }
  }
  return false;

}