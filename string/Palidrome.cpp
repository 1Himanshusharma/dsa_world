#include<iostream>
using namespace std;

bool isPalidrome(string s){
  int start = 0;
  int end = s.size() - 1;
  while (start < end){
    if (s[start++] != s[end--]){
      return false;
    }
  }
  return true;
}
int main(){
  char name[10];
  cin >> name;
  cout << "My is name is " << name << endl;
  cout << "Is my name is palidrome" ;
  if (isPalidrome(name)){
    cout << "Yes Your name is palidrome.";
  }
  else{
    cout << "No Your name is not palidrome.";
  }
}