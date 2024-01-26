#include<iostream>
#include<cmath>
using namespace std;

int min_height(int n){
  // we can make a formula with the previous formula
  return (n - 1);
}
int max_height(int n){
  return (log2(n+1) - 1);
  // i know the formula already

}
int main(){
  cout << "Enter the number of nodes: ";
  int n;
  cin >> n;
  if(n <= 0){
    cout << "Invalid input!";
    }else{
      cout << "\nMinimum height tree possible = "<< min_height(n);
      cout << "\nMaximum height tree possible = "<< max_height(n);
      }
}
