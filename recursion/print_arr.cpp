#include<iostream>
using namespace std;


// ek baar dekho kya chije chaiye
// fhir konsi chij change ho rhi hai
// index change ho rha hai or mujhe arr ki value access karni hai
// but mujhe size bhi chaiye hoga
void print(int arr[],int index,int n){
  // mujhe base condition lagani hai
  // jis condition ke liye hum ruk jayenge
  if (index >= n){
    return;
  }
  cout << arr[index] << " ";
  // next element ko print karenge
  print(arr,index+1,n);

}
int main(){
  int n;
  cout << "Enter the size of arr: ";
  cin >> n;
  int arr[n];
  for (int i =0;i<n;i++){
    // hum directly input vector me nahi le sakte but hum arr me direct input le sakte hai
    cin >> arr[i];
  }
  cout << "Elements in array are : \n";
  print(arr,0,n);
}