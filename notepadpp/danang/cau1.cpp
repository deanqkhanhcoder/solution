#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int e = 0;
    for (char c : s) {
        if (isdigit(c)) {
            int d = c - '0';
            if (d % 2 == 0) e += d;
        }
    }

    cout << e << s.size();
    return 0;
}
