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
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i){
        int a; cin >> a;
        pref[i] = pref[i - 1] + a;
    }
    auto sum = [&](int i, int j){
        return pref[j] - pref[i - 1];
    };
    vector<ll> dp(n + 1, 0);
    for (int i = n; i >= 1; --i){
        dp[i] = dp[i - 1];
        for (int x = 1; x <= 3; ++x){
            int end = min(i + x - 1, n); 
            ll ut = sum(i, end);
            int nstart = i + 2 * x;
            ll ans = ut;
            if (nstart <= n){
                ans += dp[nstart];
            }
            dp[i] = max(dp[i], ans);
        }
        // cerr << "dp[" << i << "] = " dp[i]
    }
    cout << dp[1];
    return 0;
}