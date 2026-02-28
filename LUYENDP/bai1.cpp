#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= min(i, k); ++j){
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 1] * a[i - 1]) % MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}