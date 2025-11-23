#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <cstring>
using namespace std;
constexpr int INF = (int)-2e9;
int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    int limit = 2 * n;
    int dp[limit + 1][n + 1][n + 1];
    memset(dp, 0x80, sizeof(dp));
    dp[2][1][1] = a[1][1];
    pair<int,int> d[4] = {{-1, -1}, {0, -1}, {-1, 0}, {0, 0}};
    for (int k = 3; k <= limit; ++k){
        for (int r1 = 1; r1 <= n; ++r1){
            for (int r2 = 1; r2 <= n; ++r2){
                int c1 = k - r1;
                int c2 = k - r2;
                if (c1 < 1 || c1 > n || c2 < 1 || c2 > n) continue;
                int pre = INF;
                for (int m = 0; m < 4; ++m){
                    int i = r1 + d[m].first;
                    int j = r2 + d[m].second;
                    if (i < 1 || j < 1) continue;
                    pre = max(pre, dp[k - 1][i][j]);
                }
                int ans = a[r1][c1];
                if (r1 != r2) ans += a[r2][c2];
                dp[k][r1][r2] = pre + ans;
            }
        }
    }
    cout << dp[2 * n][n][n] << endl;
    return 0;
}