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
    ll left  = a[l] + (sum[r] - sum[l]) - f(l+1, r);
    ll right = a[r] + (sum[r - 1] - sum[l - 1]) - f(l, r-1);
    return dp[l][r] = max(left, right);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    memset(dp, -1, sizeof(dp));
    cout << 2*f(1, n) - sum[n];
    return 0;
}