#include<iostream>
using namespace std;
// ye wali easy problems tho koi explaination nahi dunga

bool check(string& str,int start,int end){
  //base case
  if (start >= end){
    return true;
  }
  if (str[start] != str[end]){
    return false;
  }
  bool ans = check(str,start+1,end-1);
  return ans;

}
int main(){
  string s;
  cout << "Enter you sting: ";
  cin >> s;
  int size = s.length();
  if (!check(s,0,size-1)){
    cout << "This string is not palindrome";
  }
  else{
    cout << "This string is palidrome";
  }
}