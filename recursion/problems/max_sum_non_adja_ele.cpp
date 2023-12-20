#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//return type must be int type
// check what is always same
// need something to store values = maximum;
// need size of arr
// kya chij ho rhi hai arr ka iteration
void solve(vector<int> arr,int index,int size,vector<int>& val){
  int sum;
  if (index >= size){
    val.push_back(sum);
    return;
  }
  sum = sum + arr[index];
  for (int i = 2;i<arr.size();i++){
    solve(arr,i,size,val);
  }


  cout << "max: "<< *max_element(val.begin(),val.end());
}








//sabse phele ek bbar main funcation likh lete hai 
int main(){
  int n;
  cout << "arr ka size: ";
  cin >> n;
  vector<int> arr;
  for (int i =0;i<n;i++){
    int key;
    cin >> key;
    arr.push_back(key);
  }
  vector<int> val;
  // hume ek hi ans chaiye tho return type must be int type
  solve(arr,0,n,val);
  
}