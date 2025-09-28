#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
const int MOD = (int)1e9 + 7;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    string grid[n];
    for (int i = 0; i < n; i++) cin >> grid[i];
    int dp[m] = {0};
    if (grid[n - 1][m - 1] == '#'){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (grid[i][j] == '#'){
                dp[j] = 0;
            } else {
                if (i == 0 && j == 0) continue;
                dp[j] = (dp[j] + (j > 0 ? dp[j-1] : 0)) % MOD;
            }
        }
    }
    cout << dp[m - 1];
    return 0;
}