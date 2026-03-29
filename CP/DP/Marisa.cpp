#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string t = "marisa";
    int n = s.size(), m = t.size();
    vector<ll> dp(m + 1, 0);
    dp[0] = 1;
    for (char c : s) {
        for (int i = m; i >= 1; --i) {
            if (c == t[i - 1]) {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
        }
    }
    cout << dp[m] % MOD;
    return 0;
}
