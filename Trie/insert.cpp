#include<iostream>
using namespace std;

class Node{
  public:
  char data;
  Node **children;
  bool isterminal;
  Node(int key){
    this->data = key;
    Q = new Node*[26];
    for (int i = 0;i < 26;i++){
      Q[i] = NULL;
    }
    this->isterminal = false;
  }
};
void insertWord(Node *root,string word){
  // base case
  // so i wanna insert node into trie
  // i will take a char from the string
  if (word.length() == 0){
    root->isterminal = true;
    return;
  }
  char ch = word[0];
  int index = ch-'0';
  Node *child;
  // if that char is alresady present into trie
  if (root->children[index] != NULL){
    // then i dont need to insert that char again
    child = root->children[index];
  }
  else{
    // if absent it means i need to insert that element in trie
    child = new Node(ch);
    root->children[index] = child;
  }
  // i need to call for recursion
  insertWord(child,word.substr(1));
}

bool searchword(Node *root,string word){
  // base case
  if (word.length() == 0){
    // it means that we dont have char to serach then i will check wheather the terminal node is isterminal or !isterminal
    return root->isterminal;

  }
  // i will take a char
  char ch = word[0];
  int index = ch - 'a';
  Node *child;
  if (root->children[index] != NULL){
    // it means that node is already exist
    child = root->children[index];
  }
  else{
    // not fount
    return false;
  }
  return searchword(child,word.substr(1));
}

void deleteword(Node *root,string word){
  if (word.length() == 0){
    root->isterminal = false;
    return;
  }
  // case 1
  // take a char
  char ch = word[0];
  int index = ch-'a';
  Node *child;
  if (root->children[index] != NULL){
    // it means that is already present
    child = root->children[index];
  }
  else{
    // not foundt
    return;
  }
  deleteword(child,word.substr(1));
}
