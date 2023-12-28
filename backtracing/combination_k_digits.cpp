#include<iostream>
#include<vector>
using namespace std;
void solve(int& n,int index,int k,vector<vector<int>>& ans,vector<int> output){
  if (k == 0){
    ans.push_back(output);
    return;
  }
  //ek case solve karunga
  for (int i = index;i<=n;i++){
    output.push_back(i);
    // cursion call 
    solve(n,i+1,k-1,ans,output);
    //backtracking for different case from the starting
    output.pop_back();
  }
}



int main(){
  int n;
  cout << "please enter the number: ";
  cin >> n;
  // ex n = 4 k = 2 => [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]];
  int k;
  cin >> k;
  vector<vector<int>> ans;
  vector<int> output;
  solve(n,1,k,ans,output);
  for (int i = 0;i<ans.size();i++){
    cout << '['; 
    for (int j = 0;j<ans[0].size();j++){
      cout << ans[i][j] << ",";
    }
    cout << ']';
  }


}