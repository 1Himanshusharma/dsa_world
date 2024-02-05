#include<iostream>
using namespace std;
#include<queue>
#include <iostream>
#include "BT.h"

int main() {
  BT btree;
  btree.create();

  std::cout << "Inorder traversal: ";
  btree.inorder();
  std::cout << std::endl;

  std::cout << "Preorder traversal: ";
  btree.preorder();
  std::cout << std::endl;

  std::cout << "Postorder traversal: ";
  btree.postorder();
  std::cout << std::endl;

  std::cout << "Height of the tree: " << btree.height() << std::endl;

  std::cout << "Diameter of the tree: " << btree.diameter() << std::endl;

  std::cout << "Level order traversal: ";
  btree.levelorder();
  std::cout << std::endl;

  std::cout << "Level order traversal with line breaks: ";
  btree.levelorderII();
  std::cout << std::endl;

  return 0;
}