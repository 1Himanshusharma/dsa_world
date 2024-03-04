#include<iostream>
using namespace std;

class Heap{
  private:
  int *a;
  int size,maxsize;
  public:
  Heap(){
    this->maxsize = 10;
    this->a = new int[maxsize];
    this->size = 0;
  }
  void insert(int key){
    if (size  == maxsize) {
      cout << "Heap is full.";
      return;
    }
    size++;
    a[size] = key;
    // now i have insert the element at the end to tree
    // then i need to heapify or check wheather it is at right place or not
    int index = size;
    while (index > 1){
      int parentIndex = index/2;
      if (a[parentIndex]  < a[index]) {
        swap(a[parentIndex],a[index]);
        index = parentIndex;
      }
      else break;
    }
  }
  void display(){
    for (int i = 1; i <= size ; i++){
      cout << a[i] << " ";
    }
  }
  int del(int a[],int& size){
    int ans = a[1];
    a[1] = a[size--];
    int index = 1;
    while (index < size){
      int leftchild = 2 * index ;
      int rightchild = 2 *index + 1;
      
      int largestKaIndex = index;
      if (leftchild <= size && a[leftchild] > a[largestKaIndex]){
        largestKaIndex = leftchild;
      }
      if (rightchild <= size && a[rightchild] > a[largestKaIndex]){
        largestKaIndex = rightchild;
      }
      if (largestKaIndex != index){
        swap(a[largestKaIndex],a[index]);
        index = largestKaIndex;
      }
      else{
        break;
      }
    }
    return ans;
  }
  void heapify(int arr[],int size,int index){
      int leftchild = index * 2;
      int rightchild = index * 2 + 1;

      int largest_ka_index = index;
      if (leftchild <= size && arr[largest_ka_index] < arr[leftchild]){
        largest_ka_index = leftchild;
      }
      if (rightchild <= size && arr[largest_ka_index] < arr[rightchild]){
        largest_ka_index = rightchild;
      }
      if (largest_ka_index != index){
        swap(arr[largest_ka_index],arr[index]);
        index = largest_ka_index;
        heapify(arr,size,index);
      }
  }
  void buildHeap(int arr[],int size){
    for (int i = size/2;i > 0;i--){
      heapify(arr,size,i);
    }
  }
  void heapsort(int arr[],int size){
    for (int i = 1; i < size ;i++){
      cout << del(arr,size);
      heapify(arr,size,0);;
    }
  }
  
};

int main(){
  Heap h;
  h.insert(89);
 
  // h.insert(54);
  // h.insert(76);
  //  h.insert(34);
  

  // h.heapify();
  // cout << "The heap elements: ";
  // h.display();

  int arr[] = {-1,43,12,89,590,3,4,2,990};
  h.heapsort(arr,8);
  for (int i = 1 ; i < 8 ; i++){
    cout << arr[i] << " "; 
  }
}