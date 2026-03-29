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
    vector<vector<int>> merge(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; ++i) merge[i][i] = a[i - 1];
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            for (int k = i; k < j; ++k){
                if (merge[i][k] == -1 || merge[k + 1][j] == -1) continue;
                if (merge[i][k] == merge[k + 1][j]){
                    merge[i][j] = merge[i][k] + 1;
                    break;
                }
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) dp[i][i] = 1;
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if (merge[i][j] != -1){
                dp[i][j] = 1;
                continue;
            }
            for (int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}