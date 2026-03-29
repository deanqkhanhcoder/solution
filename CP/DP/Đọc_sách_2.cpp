#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * a[i]) % MOD;
        }
    }
    cout << dp[n][k] % MOD;
    return 0;
}
