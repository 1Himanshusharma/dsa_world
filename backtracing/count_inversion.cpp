#include<iostream>
using namespace std;
int Count_Inversion(int arr[],int size){
  int count = 0;
  for (int i = 0;i<size;i++){
    for (int j = i+1;j <size;j++){
      if (arr[i] > arr[j]){
        count++;
      }
    }
  }
  return count;
}


int main(){
  int n;
  cout << "Enter the size of arr: ";
  cin >> n;
  // Declare and initialize array
  int a[n];
  for(int i=0 ;i < n ;i++){
    cout << "Element "<< (i+1) << ": ";
    cin >> a[i] ;
    }

  int ans = Count_Inversion(a,n);
  cout << "Totat inversion: "<< ans;

}