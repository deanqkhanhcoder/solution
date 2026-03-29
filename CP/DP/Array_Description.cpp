#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MOD = (int)1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0));
    if (a[1] == 0){
        fill(dp[1].begin() + 1, dp[1].begin() + m + 1, 1);
    } else {
        dp[1][a[1]] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int v = 1; v <= m; ++v){
                dp[i][v] = ((long long)dp[i - 1][v - 1] +
                dp[i - 1][v] +
                dp[i - 1][v + 1]) % MOD;
            }
        } else {
            int v = a[i];
            dp[i][v] = ((long long)dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD;
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }
    cout << ans;
}