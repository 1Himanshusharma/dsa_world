#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
  // ye koirecursion funcation nahi hai
  // phele mene mann liya phela element pivot hai
  int pivot_index = start;
  int pivot_element = arr[start];

  // aab humara pivot_element sabko bol rha hai ki mujhe right place per bhejo
  // mujhe pta hai ki mai mere se chote logo ko count kar lunga
  // or mai uss place per chala jaunga
  int count = 0;
  for (int i = start + 1;i<end;i++){
    if (arr[i] > pivot_element){
      count++;
    }
  }
  int right_index = count + start;
  swap(arr[pivot_index],arr[right_index]);
  pivot_index = right_index;

  // aab mai bol rha hu ki jo mere left me mujh se bade hai orr right me chote hai unko swap kro
  int i = start;
  int j = end;
  while ((i < pivot_index) && (j > pivot_index)){
    while (pivot_element >= arr[i]){
      i++;
    }
    while (pivot_element < arr[j]){
      j--;
    }
    if ((i < pivot_index) && (j > pivot_index)){
      swap(arr[i],arr[j]);
    }
  }
  return right_index;

}


void mergesort(int *arr,int start,int end){
  // base condition
  if (start >= end){
    return;
  }
  int pivot_index = partition(arr,start,end);
  mergesort(arr,start,pivot_index-1);
  mergesort(arr,pivot_index+1,end);

}

int main(){
  int n;
  cout << "Enter size of arr: ";
  cin >> n;

  int arr[n];
  for (int i = 0;i<n;i++){
    cin >> arr[i];
  }
  mergesort(arr,0,n-1);
  cout << "\nSorted array is : \n";
  for (int i = 0;i<n;i++){
    cout << arr[i] << " ";
    }


}