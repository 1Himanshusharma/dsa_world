#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>& val,int start,int end){
  // base conditon
  if (start == end){
    return val[start];
  }
  // aab mere paas three conditions hai

  //first con.
  // left me sum ho
  // abb mujhe devide karna that why i need to find out mid
  int mid = start + ((end - start)>>1);
  int leftmaxsum = solve(val,start,mid);
  // second case right me sum ho
  int rightmaxsum = solve(val,mid+1,end);

  int maxleftboardersum = INT_MIN;
  int maxrightboardersum = INT_MIN;
  int leftboardersum = 0;
  int rightboardersum = 0;

  for (int i = mid ; i >= start;i--){
    leftboardersum += val[i];
    if (leftboardersum > maxleftboardersum){
      maxleftboardersum = leftboardersum;
    }
  }
  for (int i = mid + 1;i<= end ;i++){
    rightboardersum += val[i];
    if (rightboardersum > maxrightboardersum){
      maxrightboardersum = rightboardersum;
    }
  }

  int boardersum = maxleftboardersum + maxrightboardersum;

  return max(boardersum,max(leftmaxsum,rightmaxsum));

}



int main(){
  vector<int> v = {-1,-2,1,2,3};
int n = v.size();
int res = solve(v,0,n-1);
cout<<"Maximum path sum is "<<res<<endl;
return 0;

}