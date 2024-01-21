#include<iostream>
using namespace std;
#include<vector>

int main(){
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> arr;
    for (int i=0;i<n;i++){
        int key;
        cin >> key;
        arr.push_back(key);
    }
    for (int i=0;i<arr.size();i++){
        for (int j = i;j<arr.size();j++){
            cout << arr[j] << " ";
            if (j == arr.size()-1){
            
            }
        }
        cout << endl;
    }

}