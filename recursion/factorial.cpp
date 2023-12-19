#include<iostream>
using namespace std;

int factorail(int n){
  // base condition 
  // mujhe bola gya hai mai kha per end haunga or mujhe kha per value milegi
  //  or main janta hu 1 or 0 per factorail ki value 1 hoti hai
  if (n == 1){
    return 1;
  }
  int chotiproblem =  factorail(n-1);
  int badiproblem = chotiproblem * n;
  return badiproblem; 
}
int main(){
  int n;
  cout << "Enter the value: ";
  cin >> n;
  int res = factorail(n);
  cout << "factorail will be: "<< res;
}