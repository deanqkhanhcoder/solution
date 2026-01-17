#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string raw; cin >> raw;
    string s;
    for (char c : raw){
        if (s.empty() || s.back() != c) s.push_back(c);
    }
    int n = (int)s.size();
    vector<int> pos[26];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i){
        int c = s[i] - 'a';
        pos[c].push_back(i);
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len){
        for (int i = 0; i + len - 1 < n; ++i){
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + 1;
            int c = s[i] - 'a';
            for (int k : pos[c]){
                if (k <= i || k > j) continue;
                int s1 = dp[i + 1][k];
                int s2 = (k + 1 <= j ? dp[k + 1][j] : 0);
                dp[i][j] = min(dp[i][j], s1 + s2);
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}