#include<iostream>
using namespace std;

// i need one ans so i will int return type solve funcation
// it is same as previous code
// dekho kya chij change ho rhi hai, hum decrease karte ja rhe hai target ko
// isme respective recurr calls hai jo x,y,z ke saath change ho rhi hai

int solve(int x,int y,int z,int target){
  // base case
  int x1,y1,z1;
  if (target == 0){
    return 0;
  }

  // ager humare paas target -ve ho jata so what 
  // ager main int_min me + 1 karunga tho kya values hogi oviously min hoga s
  // iske alawa hum ek alternate bhi kar sakte hai
  // return -1 then -1 + 1 will become 0 still 0 is minimum segment here but reverse moving it become 0 + 1 that's why we got wrong ans
  if (target < 0){
    return -1;
  }
  // recursive call
  x1 = solve(x,y,z,target - x) + 1;
  y1 = solve(x,y,z,target - y) + 1;
  z1 = solve(x,y,z,target - z) + 1;
  

  cout << x1 <<" "<< y1<< " " << z1<<endl;
  return max(x1,max(y1,z1));
}



// sabse phele main ko likh dete hai
int main(){
  int length_of_rod;
  cin >> length_of_rod;
  // i am having x,y,z which have diff or same value;
  int x,y,z;
  x = 5;
  y = 2;
  z = 2;
  int ans = solve(x,y,z,length_of_rod);
  cout << "ans is: " << ans;

  
}