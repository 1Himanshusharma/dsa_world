#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> arr,int index,int sum,vector<int>& val){
  if (index >= arr.size()){
    val.push_back(sum);
    return;
  }
  //exclude wala case
  
  solve(arr,index+1,sum,val);
  
//include
  solve(arr,index+1,sum+arr[index],val);
  
}






int main(){
  int n;
  cout << "size of arr: ";
  cin >> n;
  vector<int> arr;
  for (int i =  0;i<n;i++){
    int key;
    cin >> key;
    arr.push_back(key);
  }
  vector<int> val;
  solve(arr,0,0,val);
  for (int i =0;i<val.size();i++){
    cout << val[i] << " ";
  }
}