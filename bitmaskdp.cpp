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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<int> dp(1 << n, 0);
    dp[0] = 1;
    for(int mask = 0; mask < (1 << n); mask++) {
        int k = __builtin_popcount(mask);
        for(int j = 0; j < n; j++) {
            if(!(mask & (1 << j)) && a[k][j] == 1) {
                dp[mask | (1 << j)] = (dp[mask | (1 << j)] + dp[mask]) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}
