#include<iostream>
#include<vector>
using namespace std;

// Today we are going to solve a very famous problem: Rat in a Maze.

// Safe place find karo
bool issafe(vector<vector<int>>& arr, int x, int y, int row, int col, vector<vector<bool>>& visited) {
    // Safe place
    // If I am in a room, I can go anywhere.
    // But outside is not safe.
    if ((x >= 0 && x < row) && (y >= 0 && y < col) && (arr[x][y] == 1) && (!visited[x][y])) {
        return true;
    }
    return false;
}

// What parameters should I pass?
// Store karne ke liye vector
void solve(vector<vector<int>>& arr, int x, int y, int row, int col, vector<vector<bool>>& visited, vector<string>& result, string path) {
    // Base case
    // Simple hai, agar main destination per pahunch gaya to
    if ((x == row - 1) && (y == col - 1)) {  // Fix: Adjust the base case condition
        result.push_back(path);
        return;
    }
    // Ab main ek baar maximum wale case ko consider karunga jisse mujhe all possibilities ka pata lagega
    // For up
    if (issafe(arr, x - 1, y, row, col, visited)) {
        visited[x - 1][y] = true;
        solve(arr, x - 1, y, row, col, visited, result, path+'U');
        // Backtrace is like when we want to find out all cases
        visited[x - 1][y] = false;
    }
    // For down
    if (issafe(arr, x + 1, y, row, col, visited)) {
        visited[x + 1][y] = true;
        solve(arr, x + 1, y, row, col, visited, result, path +'D');
        visited[x + 1][y] = false;
    }
    // For left
    if (issafe(arr, x, y - 1, row, col, visited)) {
        visited[x][y - 1] = true;
        solve(arr, x, y - 1, row, col, visited, result, path + 'L');
        visited[x][y - 1] = false;
    }
    // For right
    if (issafe(arr, x, y + 1, row, col, visited)) {
        visited[x][y + 1] = true;
        solve(arr, x, y + 1, row, col, visited, result, path + 'R');
        visited[x][y + 1] = false;
    }
}

int main() {
    // Rat in maze
    // Create vector
    // Full vector
    vector<vector<int>> arr{{1,1},{1,1}};  // Fix: Added a missing element in the array
    int n = 2;
    vector<string> res;
    string path = "";
    vector<vector<bool>> visited(2, vector<bool>(2, false)); 
    visited[0][0] = true; // Fix: Adjusted the size of the visited array
    solve(arr, 0, 0, 2, 2, visited, res, path);  // Fix: Adjusted the column size
    cout << "All possible paths : ";
    for (auto x : res) {
        cout << x << endl;
    }
    return 0;
}
