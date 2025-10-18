#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> grid[i][j];
        }
    }
    vector<ll> dp(n, 0);
    dp[0] = grid[0][0];

    for (int j = 1; j < n; ++j)
        dp[j] = dp[j-1] + grid[0][j];
    for (int i = 1; i < n; ++i) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; ++j)
            dp[j] = grid[i][j] + max(dp[j], dp[j-1]);
    }
    cout << dp[n-1];
    return 0;
}
