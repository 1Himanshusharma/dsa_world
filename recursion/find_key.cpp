#include<iostream>
using namespace std;

// dekho change kya ho rha hai = index;
// dekho value kisme access kar rhe hai = arr;
// dekho kya chij jo constant hai orr har baar chaiye = size of arr;
// dekho kya operation karne me chaiye(key) = key
// dekho kisme tumhe return chaiye bool yaa index me = dono me lakin ek baar me ek hi return funcation implement kar sakte hai
// dekho kisi me changes to nahi karne hai ager karne hai to reference to parameter lena hoga jo original value change kar deta hai



bool find(int arr[],int index, int key,int size){
  //base codition or break conditon 
  if (index >= size){
    return false;
  }
  // true condition
  if (arr[index] == key){
    return true;
  }
  bool ans = find(arr,index + 1,key,size);
  return ans;
}

//ager mai index ki values ko store karna chata hu
// store ke liye mujhe vector ya arr chaiye;
// vector use karenge
void findindex(int arr[],int index,int size,int key,vector<int>& val){
  if (index >= size){
    return;
  }
  if (arr[index] == key){
    val.push_back(index);
  }
  findindex(arr,index+1,size,key,val);
}

int main(){
  int n;
  cout << "Plese enter the size of arr: ";
  cin >> n;
  int arr[n];
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  int key;
  cout << "Enter the key value: ";
  cin >> key;
  if (find(arr,0,key,n)){
    cout <<  "true";
  }
  else{
    cout << "false";
  }
}