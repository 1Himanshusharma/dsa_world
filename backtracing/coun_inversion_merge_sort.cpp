#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr,int start,int mid,int end){
  int ls = mid - start + 1;
  int rs = end - start;
  int *a = new int[ls];
  int *b = new int[rs];
  for (int i=0;i < ls ;i++) a[i] = arr[start+i];
  for (int j=0;j < rs;j++) b[j]=arr[mid+1+j];
  int i=0 ,j=0;
  int count = 0;
  while(i < ls && j <= rs) {
    if(a[i] > b[j]){
      arr[start++ ] = b[j++ ];
      count++;
      // cout << "B["<<j<<"]"<<endl;
      } else {
        arr[start++] = a[i++];

        //cout << "A["<<i<<"]\n";
        }
  }

  while (i < ls){
    arr[start++] = a[i++];
  }
  while (j < rs){
    arr[start++] = b[j++];

  }
  return count;


}

int merge_sort(vector<int>& arr,int start,int end){
  if (start >= end){
    return 0;
  }
  int count = 0;
  int mid = (start + end)/2;
  count += merge_sort(arr,start,mid);
  count += merge_sort(arr,mid+1,end);
  count += merge(arr,start,mid,end);
  return count;

}
int main(){
  int n;
  cout << "enter the size of arr: ";
  cin >> n;
  vector<int> arr;
  cout << "Enter elements of array : \n";
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    arr.push_back(x);
    }
  //sort
  cout << merge_sort(arr,0,n-1);

}