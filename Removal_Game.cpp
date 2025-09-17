/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

static ll dp[5005][5005];
static int a[5005];
static ll sum[5005];

int n;

ll f(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    if (dp[l][r] != -1) return dp[l][r];
    ll left  = a[l] + (sum[r+1] - sum[l+1]) - f(l+1, r);
    ll right = a[r] + (sum[r] - sum[l]) - f(l, r-1);
    return dp[l][r] = max(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i-1];
    memset(dp, -1, sizeof(dp));
    cout << f(0, n-1);
    return 0;
}
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> p(n + 1, 0);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = a[i];
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            ll sum = p[r + 1] - p[l];
            dp[l][r] = sum - min(dp[l + 1][r], dp[l][r - 1]);
        }
    }

    cout << dp[0][n - 1] << "\n";
}
