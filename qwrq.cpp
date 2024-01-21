#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int> arr, int index, int n, vector<int> val, int& sum) {
  if (index >= n) {
    if (!val.empty()) {
      int minValue = *min_element(val.begin(), val.end());
      sum += minValue;
    }
    for (int i = 0;i<val.size();i++){
      cout << val[i] << " ";
    }
    cout << endl;
    return;
  }

  solve(arr, index + 1, n, val, sum);
  val.push_back(arr[index]);
  solve(arr, index + 1, n, val, sum);
}

int main() {
  int n;
  cout << "Enter the size: ";
  cin >> n;

  vector<int> arr;
  vector<int> val;
  for (int i = 0; i < n; i++) {
    int key;
    cin >> key;
    arr.push_back(key);
  }

  int sum = 0;
  solve(arr, 0, n, val, sum);
  cout << "The sum is: " << sum << endl;

  return 0;
}
