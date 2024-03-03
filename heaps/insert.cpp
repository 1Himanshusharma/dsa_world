#include<iostream>
using namespace std;
class Heap{
  private:
  int *a;
  int size;
  int capacity;
  public:
  Heap(int capacity){
    this->size = 0;
    this->capacity = capacity;
    this->a = new int[capacity];;
  }
  void insert(int x) {
    size++;
    a[size] = x;
    int index = size;
    // that means we have insert node at the end
    // i need confirm that whether that node is at right position or not
    while (index > 1){
      // i am at the child node
      // where do you want to go
      int parentIndex = index/2;
      if (a[parentIndex] < a[index]){
        swap(a[parentIndex],a[index]);
        index = parentIndex;
      } 
      else{
        break;
      }
    }
  }
  void display(){
    for (int i = 1; i <= size;i++){
      cout << a[i] << " ";
    }
  }
  // deleting processs
  // we can only delete root element from the heap
  void del(){
    // i will store root value then i will return the deleted value
    int ans = a[1];
    a[1] = a[size];
    size--;
    // i have copy the leaf node at the root postion and decrease the size in order to delete the element
    // now i will check whether all element are at correct postion or not
    int index = 1;
    while (index <= size){
      int leftindex = index/2;
      int rightindex = index/2 + 1;
      int largesKaIndex = index;
      if (leftindex <= size && a[leftindex] >  a[largesKaIndex]){
        largesKaIndex = index;
      }
      if (rightindex <= size && a[rightindex] > a[largesKaIndex]){
        largesKaIndex = index;
      }
      if (index != largesKaIndex){
        swap(a[index],a[largesKaIndex]);
        index = largesKaIndex;
      }
      else{
        break;
      }
    }
  }
  void heapify()

};
int main(){
  Heap hp(5);
  hp.insert(34);
  hp.insert(33);
  hp.insert(65);
  hp.insert(78);
  hp.display();
  hp.del();
  cout << endl;
  hp.display();
  }