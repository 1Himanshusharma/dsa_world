#include<iostream>
#include<string>
using namespace std;

// ye bhi easy question koi explaination nahi hogi
//cholo ek experiment karte hai
// with the help of return type
string solve(string& str,int start,int end){
  if (start >= end){
    return str;
  }
  swap(str[start],str[end]);
  string small = solve(str,start+1,end-1);
  return small;
}
// aab void wala 
// thik hai ek tip deta hu
//************* jab bhi referance by parameter paas ho rha hai orr tumhe ussi ke ander operation karne hai tho void best choice hai
// tum kar sakte ho bina void ke bhi but you will ended up  copying data again and again


void reverse(string& str,int start,int end){
  if (start >= end){
    return;
  }
  swap(str[start], str[end]);
  reverse(str,start+1,end-1);
  // dont you think that use void recursion ki easy to understand
}
int main(){
  string str;
  cout << "please enter your string: ";
  cin >> str;
  int n = str.length();
  string ans = solve(str,0,n-1);
  cout << "ans : "<< ans;
}