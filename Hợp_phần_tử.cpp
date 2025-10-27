#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll const INF = (ll)1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<ll> prf(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            ll ans = INF;
            for (int k = i; k < j; ++k)
                ans = min(ans, dp[i][k] + dp[k + 1][j] + (prf[j] - prf[i - 1]));
            dp[i][j] = ans;
        }
    }
    cout << dp[1][n];
    return 0;
}