#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int>& arr,int start,int end){
  // this funcation is not recursion
  // suppose that first element is pivot element
  int pivot_index = start;
  int pivot_element = arr[start];
  //find the right position of that element
  int count = 0;
  for (int i = start;i < end;i++){
    if (arr[i] <= pivot_element) {
      count++;
    }
  }

  // i found the right postion
  int right_position = count + start;
  swap(arr[right_position],arr[pivot_index]);

  pivot_index = right_position;

  int i=start,j=end;
  while ((i < pivot_index) && (j > pivot_index)){
    while (arr[i] <= pivot_element){
      i++;
    }
    while (arr[j] > pivot_element){
      j--;
    }
    swap(arr[i],arr[j]);
  }
  return pivot_index;
}


void quicksort(vector<int>& arr,int start,int end){
  if (start>=end){
    return;
  }
  int pivot_index = partition(arr,start,end);
  quicksort(arr,start,pivot_index-1);
  quicksort(arr,pivot_index+1,end);
}

int main(){
  int n;
  cout << "Enter the size of arr: ";
  cin >> n;
  vector<int> val;
  while (n >0){
    int key;
    cin >> key;
    val.push_back(key);
    n--;
  }
  int size = val.size();
  quicksort(val,0,size-1);
  for(int i = 0;i<size;i++){
    cout << val[i] << " ";
  }
}