#include<iostream>
using namespace std;

void Generate_parenthesis(string& res,int open,int close){
  if ((open == 0) && ( close == 0)){
    cout << res<< " ";
    return;
  }
  if (open > 0){
    res.push_back('(');
    Generate_parenthesis(res,open-1,close);
    res.pop_back();
  }
  if (close > open){
    res.push_back(')');
    Generate_parenthesis(res,open,close-1);
    res.pop_back();
  }
}
int main(){
  int n;
  cout << "Enter your number: ";
  cin >> n;
  string str = "";
  Generate_parenthesis(str,n,n);

}