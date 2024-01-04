#include<iostream>
#include<vector>
using namespace std;
// 
void solve(string res,int open,int close,vector<string>& ans){
  // mai bol rha hu ki ager and ager open and close is equal to zero then i can say it is final result
  if ((open == 0) && (close == 0)){
    ans.push_back(res);
    return;
  }
  // i have to recurr both funcation simultanously
  // mujhe 2 conditions ek saat true karni hai
  if (open > 0){
    res.push_back('(');
    solve(res,open-1,close,ans);
    res.pop_back();
  }
  if (close > open){
    res.push_back(')');
    solve(res,open,close-1,ans);
    res.pop_back();
  }
}

int main(){
  string str = "";
  vector<string> val;
  int n;
  cout << "ENter your number: ";
  cin >> n;
  solve(str,n,n,val);
  for (auto i:val){
    cout << i << " ";
  }
}