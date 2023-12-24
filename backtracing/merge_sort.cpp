#include<iostream>
using namespace std;

void merge(int *arr,int start,int mid,int end){
  // find the length of subarray 
  int len1 = mid - start + 1;
  int len2 = end - mid;

  //create two arr
  int *a = new int[len1];
  int *b = new int[len2];


  // copy the elements of arr into a
  for (int i = 0;i<len1;i++){
    a[i] = arr[i];
  }
  // copy the other arr
  for (int i = 0;i<len2;i++){
    b[i] = arr[mid+ i + 1];
  }

  // now merge both array:
  int i1 = 0,i2 = 0;
  int mi = start;
  while ((i1 < len1) && (i2 < len2)){
    if (a[i1] <= b[i2]){
      arr[mi++] = a[i1++];
    }
    else{
      arr[mi++] = b[i2++];
    }
  }

  // copy the rest elements
  while (i1 < len1){
    arr[mi++] = a[i1++];
  }
  while (i2 < len2){
    arr[mi++] = b[i2++];
  }
  delete [] a;
  delete [] b;
}


void mergesort(int arr[],int start,int end){
  //base condition
  if (start >= end){
    return ;
  }
  int mid = (start + end)/2;
  mergesort(arr,start,mid);
  mergesort(arr,mid+1,end);
  merge(arr,start,mid,end);

}



int main(){
  int n;
  cout << "Please enter the size of arr: ";
  cin >> n;
  int *arr = new int[n];
  for (int i = 0;i<n;i++){
    cin >> arr[i];
  }
  cout << "\nSorted Array is:\n";
  mergesort(arr,0,n-1);
  for (int i=0;i<n;i++)
  cout << arr[i] << " ";
  return 0;

}