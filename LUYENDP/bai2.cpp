#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <array>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    
    vector<array<array<ll, 2>, 2>> dp(n + 1);
    for (int i = 1; i <= n; ++i){
        dp[i][0][1] = dp[i - 1][0][0] + a[i - 1];
        dp[i][0][0] = max(dp[i - 1][1][0], dp[i - 1][1][1]) + a[i - 1];
        dp[i][1][1] = dp[i - 1][1][0] + b[i - 1];
        dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]) + b[i - 1];
    }
    ll ans = dp[n][0][0];
    ans = max(ans, dp[n][0][1]);
    ans = max(ans, dp[n][1][0]);
    ans = max(ans, dp[n][1][1]);
    cout << ans;
    return 0;
}