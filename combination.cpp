#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int>& arr, int index, vector<int>& val) {
    if (index == arr.size()) {
        for (int i = 0; i < val.size(); i++) {
            cout << val[i] << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element
    val.push_back(arr[index]);
    solve(arr, index + 1, val);
    val.pop_back();

    // Exclude the current element
    solve(arr, index + 1, val);
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        arr.push_back(key);
    }

    vector<int> val;
    solve(arr, 0, val);

    return 0;
}
