#include <iostream>
using namespace std;

bool match(string &s, int si, string &p, int pi) {
    // base case
    if ((si == s.size()) && (pi == p.size())) {
        return true;
    }
    if (pi < p.size()) {
        while (pi < p.size() && p[pi] == '*') {
            pi++;
        }
        if (pi == p.size()) {
            return true; // true if we reached the end of the pattern
        }
    }

    // one normal case
    if (si < s.size() && (s[si] == p[pi] || p[pi] == '?')) {
        bool ans = match(s, si + 1, p, pi + 1);
        return ans;
    }
    if (p[pi] == '*') {
        // there will be two cases
        // case one
        // where * consume one char
        int caseA = match(s, si + 1, p, pi);
        // where * is not consuming char
        int caseB = match(s, si, p, pi + 1);
        return caseA || caseB;
    }
    return false;
}

int main() {
    string s, p;
    cout << "Please enter your string: ";
    getline(cin, s);
    cout << "Please enter you pattern: ";
    getline(cin, p);
    bool ans = match(s, 0, p, 0);
    if (ans) {
        cout << "Wild card is matching." << endl;
    } else {
        cout << "Wild card is not matching." << endl;
    }

    return 0;
}
