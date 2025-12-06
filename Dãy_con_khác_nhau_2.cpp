#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int MOD = 123456789;

int addmod(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int submod(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    if (k == 1){
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        cout << a.size();
        return 0;
    }
    for (int &e : a) cin >> e;
    vector<vector<int>> dp(n, vector<int>(k, 0));
    vector<vector<int>> last(2001, vector<int>(k, 0));
    for (int i = 0; i < n; ++i) dp[i][1] = 1;
    for (int j = 2; j <= k; ++j){
        int pre = 0;
        for (int i = 0; i < n; ++i){
            int v = a[i];
            dp[i][j] = pre;
            dp[i][j] = submod(dp[i][j], last[v][j]);
            last[v][j] = addmod(last[v][j], dp[i][j]);
            pre = addmod(pre, dp[i][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = addmod(ans, dp[i][k]);
    cout << ans;
    return 0;
}