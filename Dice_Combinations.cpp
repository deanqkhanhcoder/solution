#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> dp(6, 0);
    dp[0] = 1;
    int ws = dp[0];

    for (int i = 1; i <= n; i++) {
        int cur = ws % MOD;
        ws = (ws + cur) % MOD;
        if (i >= 6) ws = (ws - dp[i % 6] + MOD) % MOD;
        dp[i % 6] = cur;
    }

    cout << dp[n % 6] << "\n";
}
