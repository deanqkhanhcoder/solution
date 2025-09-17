#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using uc = unsigned char;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<pair<int,int>> cost(256);
    for (int i = 0; i < n; ++i){
        char c; cin >> c;
        int a; cin >> a;
        int b; cin >> b;
        cost[(uc)c] = {a, b};
    }
    vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
    for (int len = 2; len <= m; ++len) {
        for (int i = 1; i + len - 1 <= m; ++i) {
            int j = i + len - 1;
            if (s[i-1] == s[j-1]) {
                dp[i][j] = dp[i+1][j-1];
            } else {
                    dp[i][j] = min(
                        dp[i+1][j] + min(cost[(uc)s[i-1]].first, cost[(uc)s[i-1]].second),
                        dp[i][j-1] + min(cost[(uc)s[j-1]].first, cost[(uc)s[j-1]].second)
                    );
            }
        }
    }

    cout << dp[1][m] << "\n";
    return 0;
}
