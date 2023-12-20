#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int> arr,int index,vector<int> val1,vector<vector<int>>& result){
  if (index >= arr.size()){
    result.push_back(val1);
    return;
  }
  // whi subset hai tho include and exclude wala solution
  // 1 case mai solve karunga buus
  // include wali conditon
  // so mujhe arr include values ko val1 me store karana hai orr val1 ko result me push_back karna hai
  val1.push_back(arr[index]);
  solve(arr,index+1,val1,result);
  val1.pop_back();
  solve(arr,index+1,val1,result);
}

int main(){

}