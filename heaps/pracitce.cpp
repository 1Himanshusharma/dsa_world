#include<iostream>
using namespace std;
class Heap{
  private:
  int size;
  int maxsize;
  int *Q;
  public:
  Heap(int maxsize){
    this->maxsize = maxsize;
    this->size = 0;
    Q = new int[maxsize];
  }
  void insert(int key){
    if (size == maxsize) {
      cout << "heap is full";
      return;
    }
    size++;
    Q[size] = key;
    int i = size;
    while (i > 1){
      int parent_index = i/2;
      if (Q[parent_index] < Q[i]){
        int temp = Q[parent_index];
        Q[parent_index] = Q[i];
        Q[i] = temp;
        i = parent_index;
      }
      else{
        break;
      }
    }
  }
  void display(){
    for (int i = 1;i <= maxsize; i++){
      cout << Q[i] << " ";
    }
  }
  void heapify(int index){
    if (index >= size){
      return;
    }
    int left_child = index * 2;
    int right_child = index*2 + 1;
    int largest_ka_index = index;
    if (left_child < size && Q[left_child] > Q[largest_ka_index]){
      largest_ka_index = left_child;
    }
    if (right_child < size && Q[right_child] > Q[largest_ka_index]){
      largest_ka_index = right_child;
    }
    if (largest_ka_index != index){
      swap(Q[largest_ka_index],Q[index]);
      heapify(largest_ka_index);
    }
  }

  
  int del(){
    if (size == 0){
      cout << "Heap is empty.";
      return -1;
    }
    int temp = -1;
    temp = Q[1];
    Q[1] = Q[size--];
    heapify(1);
    return temp;
  }
};
void heapify(,int arr[],int index,int size){
  if (index <= size){
    return;
  }
  int left_child = 2 * index;
  int right_child = 2 * index + 1;
  int largest_ka_index = index;
  if (left_child < size && arr[largest_ka_index] < arr[left_child]){
    largest_ka_index = left_child;
  }
  if (right_child < size && arr[largest_ka_index] < arr[right_child]){
    largest_ka_index = right_child;
  }
  if (largest_ka_index != index){
    swap(arr[largest_ka_index],arr[index]);
    heapify(largest_ka_index);
  }
}



int main(){
  int arr[] = {0,1,2,3,4,5,6,7,8};
  Heap H(8);
  for (int i = 1; i < 9;i++){
    H.insert(arr[i]);
  }
  cout << "\nHeap after inserting elements: ";
  H.display();
  cout << endl;
  cout << "Min element in the heap :"<<H.del();
}