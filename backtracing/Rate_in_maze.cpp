#include<iostream>
using namespace std;
#include<vector>
bool issafe(int x,int y,int row,int col,vector<vector<int>> arr,vector<vector<bool>>& visited){
  if ((x >= 0 && x < row) && (y >=0 && y < col) && arr[x][y] == 1 && visited[x][y] == false){
    return true;
  }
  return false;
}
void solve(int i,int j,int row,int col,vector<vector<int>> arr,vector<vector<bool>>& visited,vector<string>& path,string output){
  // base condition
  if (i == row - 1 && j == col - 1){
    path.push_back(output);
    return;
  }
  // for top
  if (issafe(i-1,j,row,col,arr,visited) == true){
    visited[i-1][j] = true;
    solve(i-1,j,row,col,arr,visited,path,output + "T");
    visited[i-1][j] = false;
  }
  // for down
  if (issafe(i+1,j,row,col,arr,visited) == true){
    visited[i+1][j] = true;
    solve(i+1,j,row,col,arr,visited,path,output+"D");
    visited[i+1][j] = false;
  }
  // for left
  if (issafe(i,j+1,row,col,arr,visited) == true){
    visited[i][j+1] = true;
    solve(i,j+1,row,col,arr,visited,path,output + "R");
    visited[i][j+1] = false;
  }
  // for right
  if (issafe(i,j-1,row,col,arr,visited) == true){
    visited[i][j-1] = true;
    solve(i,j-1,row,col,arr,visited,path,output + "L");
    visited[i][j-1] = false;
  }
}
int main(){
  vector<vector<int>> arr = {{1,1,0},{1,0,1},{1,1,1}};
  int n = arr.size();
  vector<string> paths;
  vector<vector<bool>> visited(n , vector<bool>(n ,false));
  string output ="";
  solve(0,0,n,n,arr,visited,paths,output);
  cout << "All possible paths are : \n";
  for (auto i: paths){
    cout << i << "\n";
    }
}