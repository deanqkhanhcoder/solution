#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<ll> dp(k + 1, 0);
    dp[0] = 1;
    for (int e : a) {
        for (int i = e; i <= k; ++i)
            dp[i] = (dp[i] + dp[i - e]) % MOD;
    }
    cout << dp[k];
    return 0;
}