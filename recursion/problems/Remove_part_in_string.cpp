#include<iostream>
using namespace std;
#include<string>


void sovle(string& s,string& part){
  int pos = s.find(part);
  while (pos != string::npos){
    s.erase(pos,part.length());
    pos = s.find(part);
  }
}

int main(){
  string s = "absskjfnkasfnlka";
  string part = "a";
  cout<<"The original string is: \t\t"<<s<<endl;
  cout<<"\nThe substring to be removed is:\t"<<part<<endl;
  sovle(s,part);
  cout<<"\nAfter removing the substring,\nthe new string becomes:\t"<<s <<endl;


}