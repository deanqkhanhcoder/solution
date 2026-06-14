#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(26, vector<int>(n + 1, 0));
    for (char c = 'a'; c <= 'z'; ++c){
        int pos = c - 'a';
        for (int l = 0; l < n; ++l){
            int change = 0;
            for (int r = l; r < n; ++r){
                change += (s[r] != c);
                dp[pos][change] = max(dp[pos][change], r - l + 1);
            }
        }
        for (int k = 1; k <= n; ++k)
            dp[pos][k] = max(dp[pos][k], dp[pos][k - 1]);
    }
    int q; cin >> q;
    while(q--){
        int m; char c;
        cin >> m >> c;
        int pos = c - 'a';
        cout << dp[pos][m] << endl;
    }
    return 0;
}