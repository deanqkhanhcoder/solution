#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
constexpr int INF = (int)1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<vector<int>> val(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i){
        val[i][i] = a[i - 1];
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            for (int k = i; k < j; ++k){
                if (val[i][k] != -1 && val[i][k] == val[k + 1][j]){
                    val[i][j] = val[i][k] + 1;
                    dp[i][j] = 1;
                    break;
                }
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
