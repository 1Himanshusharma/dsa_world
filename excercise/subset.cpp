#include<iostream>
#include<vector>
using namespace std;

void generateSubsets(vector<int>& arr, int index, int size, vector<int> temp) {
    if (index == size) {
        // Print the current subset
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element in the subset
    temp.push_back(arr[index]);
    generateSubsets(arr, index + 1, size, temp);

    // Exclude the current element from the subset
    temp.pop_back();
    generateSubsets(arr, index + 1, size, temp);
}

int main() {
    cout << "Enter the size of arr: ";
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        arr.push_back(key);
    }

    vector<int> temp;
    generateSubsets(arr, 0, n, temp);

    return 0;
}



// whenever you listen about the subset //
// the first that should come up in your mind is 
// include and exclude method
// it includes all the subsets possible with time complexity of O(n2);

// #include<iostream>
// #include<vector>
// using namespace std;

// void solve(vector<int>& arr,int index,int size,vector<int>& temp){
//   // yyar dekho to kya change ho rha hai iteration me
//   if (index == size){
//     // ager main iterate karte hue last tak phuch gya tho main temp me jo bhi bacha hai usse print kra dunga
//     for (int i=0;i < temp.size();i++){
//       cout << temp[i] << " ";
//     }
//     cout << endl;
//     return;
//   }
//   // so yaar ek baar to test case include kro
//   // dusari baar usko nikal do
//   // nikalna hoga mai pop kar dunga or current element ko skip kardunga
//   temp.push_back(arr[index]);
//   solve(arr,index+1,size,temp);
//   temp.pop_back();
//   // bhai ager to age move nahi karega to infinte loop me rhe jayenge
//   solve(arr,index+1,size,temp);

// }
// int main(){
//   cout<< "Enter the size of arr: ";
//   int n;
//   cin >> n;
//   vector<int> arr;
//   while (n--){
//     int key;
//     cin >>key;
//     arr.push_back(key);

//   }
//   vector<int> temp;

//   solve(arr,0,n,temp);
// }

