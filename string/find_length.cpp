#include<iostream>
using namespace std;

int find_length(char s[],int size){
  int count = 0;
  for (int i = 0; i < size ; i++){
    if (s[i] == '\0'){
      count++;
    }
  }
  return count;
}
int main(){
  char  str1[] = "Hello World";
  cout << "Length of the string is :";
  int size = sizeof(str1);
  cout << find_length(str1,size)<<endl;
}