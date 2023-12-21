#include<iostream>
using namespace std;
#include<string>

void solve(string& s,string& part){
  // base case 
  int found = s.find(part); // return the position of part 
  if (found != string::npos){// npos usually indicate absence of valid postion
      string left_str = s.substr(0,found);
      string right_str = s.substr(found + part.size(),s.size());
      s = left_str + right_str;
      solve(s,part);

  }
  else{
    return;
  }
}

int main(){
  string str=  "asfsasgasgasdgasgasgasga";
  string part = "as";
  cout << "Original String : \t"<< str << endl;
  solve(str,part);
  cout << "\nModified String:\t"<< str ;
  return 0;

}