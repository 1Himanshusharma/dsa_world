#include <iostream>
#include <vector>
using namespace std;

void solve(int index, const int arr[], size_t size, int target, vector<int>& output, vector<vector<int>>& result, int sum) {
    // base condition 
    // I know that if the sum is greater than target then simply return
    if (sum > target) {
        return;
    }
    if (sum == target) {
        result.push_back(output);
        return;
    }

    for (size_t i = 0; i < size; i++) {
        output.push_back(arr[i]);
        solve(i, arr, size, target, output, result, sum + arr[i]);
        output.pop_back();
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int key = 5;

    vector<vector<int>> result;
    vector<int> val;
    solve(0, arr, sizeof(arr) / sizeof(arr[0]), key, val, result, 0);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
