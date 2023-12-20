#include<iostream>
#include<vector>
using namespace std;

void solve(int index,int arr[],int size,int target,string output,int sum){
  // base condition 
  // i know that if the sum is greater than target then simply return
  if (sum > target){
    return;
  }
  if (sum == target){
    cout << output << endl;
    return;
  }
  for (int i=0;i<size;i++){
    solve(i,arr,size,target,output + to_string(arr[i]) + " ",sum + arr[i]);
  }
}



int main(){
  int arr[] = {1,2,3};
  int key = 5;
  //solve
  string out = "";
  solve(0,arr,sizeof(arr)/sizeof(arr[0]),key,"",0);
  return 0;
  
}