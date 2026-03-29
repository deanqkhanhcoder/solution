#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> w(n);
    for (auto &e : w) cin >> e;
    int s = 1 << n;
    vector<pair<int,int>> dp(s, {n+1, 0});
    dp[0] = {1, 0};
    for (int m = 0; m < s; ++m){
        for (int i = 0; i < n; ++i){
            if ((m & (1 << i)) == 0) {
                int nm = m | (1 << i);
                if (dp[m].second + w[i] <= x){
                    dp[nm] = min(dp[nm], {dp[m].first, dp[m].second + w[i]});
                } else {
                    dp[nm] = min(dp[nm], {dp[m].first + 1, w[i]});
                }
            }
        }
    }
    cout << dp[s-1].first;
    return 0;
}