#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int MAXA = (int)1e5;
constexpr int INF = (int)1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<int>> far(k + 1, vector<int>(n + 1, 0));
    vector<int> freq(MAXA + 1, 0);
    for (int rem = 0; rem <= k; ++rem){
        int l = 1, bad = 0;
        fill(freq.begin(), freq.end(), 0);
        for (int r = 1; r <= n; ++r){
            freq[a[r]]++;
            bad += (freq[a[r]] > m);
            while (bad > rem){
                bad -= (freq[a[l]] > m);
                freq[a[l]]--;
                l++;
            }
            far[rem][r] = l;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= k; ++j){
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            for (int rem = 0; rem <= j; ++rem){
                int p = far[rem][i];
                dp[i][j] = min(dp[i][j], dp[p - 1][j - rem] + 1);
            }
        }
    }
    int ans = INF;
    for (int j = 0; j <= k; ++j) ans = min(ans, dp[n][j]);
    cout << ans;
    return 0;
}