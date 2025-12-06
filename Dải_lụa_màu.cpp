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
    for (char c: raw){
        if (s.empty() || s.back() != c) s.push_back(c);
    }
    int n = s.size();
    vector<int> pos[26];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i){
        pos[s[i] - 'a'].push_back(i);
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len){
        for (int l = 0; l + len - 1 < n; ++l){
            int r = l + len - 1;
            dp[l][r] = dp[l][r - 1] + 1;
            char c = s[r];
            for (int k : pos[c - 'a']){
                if (k < l || k >= r) continue;
                int s1 = dp[l][k];
                int s2 = (k + 1 <= r - 1 ? dp[k + 1][r - 1] : 0);
                dp[l][r] = min(dp[l][r],s1 + s2);
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}