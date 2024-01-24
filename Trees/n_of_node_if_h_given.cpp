#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int min_nodes(int height){
  return (height + 1);
}

int max_nodes(int height){
  return (pow(2,(height+1)) - 1);
}

int main(){
  cout << "Enter the hight of tree: ";
  int height;
  cin >> height;
  int min_n,max_n;
  if (height == 0){
    min_n = 1;
    max_n = 1;
  }
  else{
    min_n = min_nodes(height);
    max_n = max_nodes(height);
  }
  cout<<"Minimum number of nodes in a full binary tree with given height is : " <<min_n<<endl;
  cout<<"Maximum number of nodes in a full binary tree with given height is : " <<max_n<<endl;
}