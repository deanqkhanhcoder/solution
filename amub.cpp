#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 9;
ll add(ll a, ll b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
ll mul(ll a, ll b){
    return (a * b) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> c(n);
    for (int i = 0; i < n; ++i){
        c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    vector<vector<ll>> C(m + 1, vector<ll>(k + 1, 0));
    for (int i = 0; i <= m; ++i){
        C[i][0] = 1;
        for (int j = 1; j <= min(i, k); ++j){
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
    vector<ll> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = k; j > 0; --j){
            if (c[i] >= j){
                dp[j] = add(dp[j], mul(dp[j - 1], C[c[i]][j]));
            }
        }
    }
    cout << dp[k];
    return 0;
}

