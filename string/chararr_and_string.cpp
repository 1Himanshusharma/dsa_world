#include<iostream>
using namespace std;
int find_length(char s[],int size){
  int length =0;
  for (int i = 0 ;i < size ; i++){
    if (s[i] == '\0'){
      break;
    }
    length++;
  }
  return length;
}


int main(){
  char str[10] = "himanshu";
  // size of char array;
  cin.getline(str,9);
  cout << "The size of char arr: " << sizeof(str) << endl;
  // so what are hoping what will answer
  // i am hoping that the answer will be the size of arr because ssize of arr and each element block size is 1 so that the sizee of char arr will be equal to the arr
  


  // if you want to find the length of the word that is written inside that str;
  // use find length or size;
  
  cout << "the size: " << find_length(str,sizeof(str));

  //another method of creating the string
  string s ;
  getline(cin ,s);

  cout << "size of s: " << s.size() << " " << s.length();

  // comparing the strings
  string my_name = "Himanshu sharma";
  string other_name = "Himanshu sharma";
  if (my_name.compare(other_name) == 0){
    cout << "they are equal.";
  }
  else{
    cout << "they are not equal.";
  }

  // inserting
  my_name.insert(9,"kumar");
  cout << my_name;


  // appending
  my_name.append(other_name);


  // finding substring
  int pos = my_name.find("himashu");
  // return the first index of subtring

  //substr  
  my_name.substr(1,3);
}