#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> prev(n + 1, 0), curr(n + 1, 0);
    prev[0] = 1;
    for (char c : s) {
        memset(curr.data(), 0, (n + 1) * sizeof(ll));
        for (int j = 0; j <= n; j++) {
            if ((c == '(' || c == '?') && j != 0)
                curr[j] = (curr[j] + prev[j - 1]) % MOD;
            if ((c == ')' || c == '?') && j + 1 <= n)
                curr[j] = (curr[j] + prev[j + 1]) % MOD;
        }
        swap(prev, curr);
    }

    cout << prev[0] % MOD;
}
