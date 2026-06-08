#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    string s; cin >> s;
    int n = (int)s.size();
    vector<vector<bool>> pal(n + 1, vector<bool>(n + 1, false));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i){
        pal[i][i] = true;
        dp[i][i] = 1;
        if (i + 1 <= n){
            pal[i][i + 1] = (s[i - 1] == s[i]);
            dp[i][i + 1] = 2 + pal[i][i + 1];
        }
    }
    for (int len = 3; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            pal[i][j] = (s[i - 1] == s[j - 1] && pal[i + 1][j - 1]);
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + pal[i][j];
        }
    }
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << dp[l][r] << endl;
    }
    return 0;
}