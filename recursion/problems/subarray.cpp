#include<iostream>
using namespace std;
#include<vector>

void solve(vector<int> nums,int index,vector<int> val){
  if (index >= nums.size() ){
    for (int i = 0 ; i < val.size();i++){
      cout << val[i] << " ";
    }
    cout << endl;
    return;
  }
  val.push_back(nums[index]);

}


int main(){
  vector<int> arr = {1,2,3};
  solve(arr,0,{});
}