#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll INF = (ll)1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i){
        int a; cin >> a;
        pref[i] = pref[i - 1] + a;
    }
    auto sum = [&](int l, int r){
        return pref[r] - pref[l - 1];
    };
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            ll ans = INF;
            for (int k = i; k < j; ++k){
                ans = min(ans, dp[i][k] + dp[k + 1][j] + sum(i, j));
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[1][n];
    return 0;
}