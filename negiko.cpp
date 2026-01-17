#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int MAXN = 1000;
constexpr int MAXM = 1000;
constexpr int MAXK = 10;
constexpr int MOD = (int)1e9 + 9;
int dp[MAXN + 1][MAXM + 1][MAXK + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            dp[i][j][0] = 1;
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            for (int t = 1; t <= k; ++t){
                ll ans = dp[i - 1][j][t] + dp[i][j - 1][t];
                ans -= dp[i - 1][j - 1][t];
                ans %= MOD;
                ans += (ans < 0 ? MOD : 0);
                if (a[i] > b[j]) ans = (ans + dp[i - 1][j - 1][t - 1]) % MOD;
                dp[i][j][t] = ans;
            }
        }
    }
    cout << dp[n][m][k];
    return 0;
}
