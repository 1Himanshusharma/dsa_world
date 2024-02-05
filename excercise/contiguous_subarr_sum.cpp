#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> arr,int target){
  vector<int> result;
  int start = 0;
  int end = 0;

  if (target == 0){
    for (int i = 0;i < arr.size();i++){
      if (arr[i] == 0){
        return {i+1,i+1};
      }
    }
    return {-1};
  }
  int current_sum = 0;
  while (end < arr.size()){
    current_sum += arr[end++];
    while (current_sum > target && start < end){
      current_sum -= arr[start++];
    }
    if (current_sum == target){
      result.push_back(start+1);
      result.push_back(end);
      return result;
    }
  }
  return {-1};
}


int main(){
  cout << "Pleae eneter the size of the arr: ";
  int n;
  cin >> n;
  vector<int> val;
  while (n--){
    int key;
    cin >> key;
    val.push_back(key);
  }
  cout << "Please enter the target sum";
  int s;
  cin >> s;

  vector<int> ans = solve(arr,)
}