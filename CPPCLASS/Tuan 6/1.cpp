#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<array<ll, 3>> dp(n + 1);
    for (int i = 1; i <= n; ++i){
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + a[i - 1];
        dp[i][2] = dp[i - 1][1] + a[i - 1];
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    return 0;
}