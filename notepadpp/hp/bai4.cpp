#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                int best = INF;
                for (int k = i; k < j; ++k)
                    best = min(best, dp[i][k] + dp[k + 1][j]);
                if (s[i] == s[j]) {
                    if (i + 1 <= j - 1) best = min(best, dp[i + 1][j - 1]);
                    else best = 1;
                }
                dp[i][j] = best;
            }
        }

        cout << dp[0][n - 1] << '\n';
    }
    return 0;
}
