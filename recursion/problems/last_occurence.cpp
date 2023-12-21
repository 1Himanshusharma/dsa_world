#include<iostream>
#include<vector>
using namespace std;

// batao kha se start kru


void solve(vector<int>& arr,int index,int target,int& ans){
  if (index < 0){
    return;
  }
  if (arr[index] == target){
    ans = index;
    return;
  }
  solve(arr,index - 1,target,ans);
}

int main(){
  vector<int> arr;
  int n;
  cout << "enter the legth: ";
  cin >> n;
  for (int i = 0;i<n;i++){
    int key;
    cin >> key;
    arr.push_back(key);
  }
  int key;
  cout << "Enter the key value: ";
  cin >> key;
  int ans = -1;
  solve(arr,arr.size()-1, key,ans);
  if (ans != -1){
    cout << "ans : "<< ans;
  }
  else{
    cout << "No element is found.";
  }
}