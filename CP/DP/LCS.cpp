#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string res;
    while(dp[n][m] > 0){
        if (s[n - 1] == t[m - 1]){
            res.push_back(s[n - 1]);
            n--; m--;
        } else if (dp[n - 1][m] > dp[n][m - 1]) n--;
        else m--;
    }
    reverse(res.begin(), res.end());
    cout << res;
}
