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
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    vector<vector<char>> dp(n, vector<char>(n, 0));
    for (int i = 0; i < n - 1; ++i){
        dp[i][i] = 1;
        if (s[i] == s[i + 1]) dp[i][i + 1] = 1;
    }
    dp[n - 1][n - 1] = 1;
    for (int len = 3; len <= n; ++len){
        for (int l = 0; l + len - 1 < n; ++l){
            int r = l + len - 1;
            if ((s[l] == s[r]) && dp[l + 1][r - 1]) dp[l][r] = 1;
            else dp[l][r] = 0;
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        l--; r--;
        cout << (dp[l][r] ? "YES" : "NO") << "\n";
    }
    return 0;
}