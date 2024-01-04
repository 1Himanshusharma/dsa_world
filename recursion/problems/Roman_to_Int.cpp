#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, string>> mp = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

string solve(int num) {
    // base case
    if (num == 0) {
        return "";
    }
    for (auto i : mp) {
        if (num >= i.first) {
            string a = "";
            if (num >= 100) {
                a = solve(num / i.first);
            }
            string b = i.second;
            string c = "";
            if (num % i.first != 0) {
                c = solve(num % i.first);
            }
            return a + b + c;
        }
    }
    return "";
}

int main() {
    int n;
    cout << "Enter your number: ";
    cin >> n;
    string result = solve(n);
    cout << "Roman to Integer: " << result << endl;
    return 0;
}
