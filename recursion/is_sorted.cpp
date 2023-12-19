#include<iostream>
#include<vector>
using namespace std;

// check what is changing
// check what is always same size
// check kisme operation kar rhe hai arr
bool is_sorted(int index,int size,vector<int>& val){
  if (index == size-1){
    return true;
  }
  if (val[index] < val[index+1]){
    return false;
  }
  return is_sorted(index + 1,size,val);
}

int main(){
  int n;
  cout << "Please enter any value: ";
  cin >> n;
  vector<int> val;
  for (int i = 0;i<n;i++){
    int key;
    cin >> key;
    val.push_back(key);
  }
  if (is_sorted(0,n,val)){
    cout << "array is sorted.";
  }
  else{
    cout << "array is not sorted.";
  }
}