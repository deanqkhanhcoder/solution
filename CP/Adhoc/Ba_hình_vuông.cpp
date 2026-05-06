#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int a; cin >> a;
            pref[i][j] = a + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    auto query = [&](int x1,int y1,int x2,int y2) -> int{
        return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
    };
    vector<vector<array<int, 4>>> dp(n + 1, vector<array<int, 4>>(m + 1, array<int, 4>{}));
    for (int choose = 1; choose <= 3; ++choose){
        for (int i = k; i <= n; ++i){
            for (int j = k; j <= m; ++j){
                dp[i][j][choose] = max({
                    dp[i][j - 1][choose],
                    dp[i - 1][j][choose]
                });
                int sum = query(i - k + 1, j - k + 1, i, j);
                dp[i][j][choose] = max({
                    dp[i][j][choose],
                    dp[i - k][j][choose - 1] + sum,
                    dp[i][j - k][choose - 1] + sum
                });
            }
        }
    }   
    cout << dp[n][m][3];
    return 0;
}