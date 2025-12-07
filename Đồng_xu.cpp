#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    const int INF = 1e9;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int e : a) {
        for (int i = e; i <= k; ++i)
            dp[i] = min(dp[i], dp[i - e] + 1);
    }
    if (dp[k] == INF) cout << -1;
    else cout << dp[k];
    return 0;
}