#include<iostream>
#include<vector>
using namespace std;

void subarray(vector<int> arr, int index, int size, vector<int> temp) {
    if (index >= size) {
        for (auto i : temp) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    // calling the funcaton parallel
    // using the for loop
    for (int i = index; i < size; i++) {
      temp.push_back(arr[i]);
      subarray(arr, 1 + i, size, temp);

    }
    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    while (n--) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    cout << "Original array: ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> temp;
    // again calling recursion
    // yaar ye to bruteforce approach hai
    // khuch orr tarika batao
    
    for (int i= 0;i < arr.size();i++){
      subarray(arr, i, arr.size(), temp);

    }
    
    return 0;
}
