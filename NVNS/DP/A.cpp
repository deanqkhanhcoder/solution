#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MOD = 2111992;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= k; ++i){
        dp[i] = dp[i - 1] + 1;
    }
    for (int i = k + 1; i <= n; ++i){
        dp[i] = (dp[i - 1] + dp[i - k - 1]) % MOD;
    }
    cout << dp[n];
    return 0;
}