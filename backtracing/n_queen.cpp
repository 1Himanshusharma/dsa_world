#include<iostream>
#include<vector>
using namespace std;

void printsolution(vector<vector<int>>& board,int n){
  for (int i=0;i<n;i++){
    for (int j = 0;j<n;j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
bool issafe(int row,int col,vector<vector<int>>& board,int n){
  int i = row;
  int j = col;
  // fow left side
  while (j >= 0){
    if (board[i][j] == 1){
      return false;
    }
    j--;
  }
  // fow bottem left
  i = row;
  j = col;
  while (i < n && j >= 0){
    if (board[i][j] == 1){
      return false;
    }
    j--;
    i++;
  }
  // for up and left
  i = row;
  j = col;
  while (i >= 0 && j >= 0){
    if (board[i][j] == 1){
      return false;
    }
    j--;
    i--;
  }
  return true;
}
void solve(vector<vector<int>>& board,int col,int n){
  // base case
  if (col >= n){
    
  }
}