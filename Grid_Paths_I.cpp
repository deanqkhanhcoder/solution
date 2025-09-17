#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
const int MOD = (int)1e9 + 7;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string grid[n];
    for (int i = 0; i < n; i++) cin >> grid[i];
    int dp[n + 1] = {0};
    if (grid[0][0] == '.'){
        dp[1] = 1;
    } else {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (grid[i - 1][j - 1] == '*'){
                dp[j] = 0;
            } else if (i != 1 || j != 1) {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
    }
    cout << dp[n];
}