#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++) {
                ll cost = dp[i][k] + dp[k + 1][j] + (pref[j] - pref[i - 1]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << dp[1][n];
}
