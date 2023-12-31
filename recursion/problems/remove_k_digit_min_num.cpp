#include<iostream>
#include<string>
using namespace std;
string removeKdigits(string str,int k){
  // if we have left 0 element to remove
  if (k == 0){
    return str;
  }
  // suppose that if the len of str is less the number of element to removed
  int len = str.size();
  if (len <= k){
    return "";
  }

  // i am assuming that the first number is from first K+1
  int min_index = 0;
  // findg the lowest char
  for (int i = 1;i<= k;i++){
    if (str[i] < str[min_index]){
      min_index = i;
    }
  }
  string bacchi_hui_string = str.substr(min_index + 1);
  char temp_res = str[min_index];
  // bachi_hui_string me recursion
  string final_string = temp_res + removeKdigits(bacchi_hui_string,k-min_index);
  return final_string;
}
int main(){
  string str;
  cout << "Enter your string: ";
  cin >> str;
  int k;
  cout << "Enter no.of elements to be removed :";
  cin >> k;
  cout<<"The resultant string after removing k digits are:"<<removeKdigits(str,k)<<endl;
  return 0;
}