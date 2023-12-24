#include<iostream>
using namespace std;
int partition(int arr[],int start,int end){
  // ye koi recursion funcation nahi hai
  // okay mai mann rha hu ki first element is pivot
  int pivot_index = start;
  int pivot_element = arr[start];
  // now aab mai iss wale element ki right place find karunga
  // ager mai count use kar lu
  // tho mujhe pta chal jayega mujhe kitna chalna padhega right place tak jane ke liye
  int count = 0;
  for (int i = start + 1;i<end;i++){
    if (arr[i] > pivot_element){
      count++;
    }
  }
  //aab mujhe pta ki kitna chalna
  // mai wha per ja kar use bolunga ki tu meri jagah chala or meri place ye hai
  int right_index = start+count;
  swap(arr[right_index],arr[pivot_index]);
  pivot_index = right_index;

  // aab mai right place per hu
  // mene dono side walo se bola ki jo bhi mujhse chota bada apni place exchange kar lo
  int i = start;
  int j = end;
  while ((i < pivot_index) && (j > pivot_index)){
    while (arr[i] <= pivot_element){
      i++;
    }
    while (arr[j] > pivot_element){
      j--;
    }
    if ((i < pivot_index) && (j > pivot_index)){
      swap(arr[i],arr[j]);
    }
  }
  return pivot_index;
  

}
void quicksort(int arr[],int start,int end){
  if (start >= end){
    return;
  }
  int pivot = partition(arr,start,end);
  quicksort(arr,start,pivot-1);
  quicksort(arr,pivot+1,end);

}




int main(){
  int n;
  cout << "Please enter size of arr: ";
  cin >> n;
  // Declare and initialize array
  int arr[n];
  cout << "Enter elements of array:" << endl;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
    }
    // Call the function to sort the array using QuickSort algorithm.
    quicksort(arr,0,n-1);
    // Print sorted array
    cout << "\n\nThe Sorted Array is : \n";
    for (int i = 0;i<n;i++){
      cout << arr[i] << " ";
    }
    return 0;
  // Call the function to sort the array using QuickSort algorithm.

}