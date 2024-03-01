#include<iostream>
using namespace std;

int main(){
  string yor_family_info = "My family have 5 members";
  string *father = &yor_family_info; 
  string *me = &yor_family_info;

  cout << "father: " << *father << endl;
  cout << "me" << *me;
}