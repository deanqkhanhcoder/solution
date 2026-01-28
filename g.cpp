#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    cin >> s;
    int n = (int)s.size();

    dp.resize(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i <= n - len + 1; ++i){
            int j = i + len - 1;
            if (s[i - 1] == s[j - 1]) 
                dp[i][j] = dp[i + 1][j - 1];
            else 
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }

    cout << dp[1][n];
    return 0;
}
