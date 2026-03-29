#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> pref;
const ll INF = (ll)4e18;
int mod(int l, int r){
    int val = pref[r] - pref[l - 1];
    if (val < 0) val += 100;
    return val % 100;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n+1);
    pref.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = (pref[i-1] + a[i]) % 100;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            ll ans = INF;
            for (int k = i; k < j; ++k) {
                ans = min(ans, dp[i][k] + dp[k+1][j] 
                       + 1LL * mod(i,k) * mod(k+1,j));
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[1][n];
    return 0;
}
