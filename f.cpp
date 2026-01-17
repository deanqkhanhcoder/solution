#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int MOD = 123456789;
constexpr int MAXN = (int)1e6;
int pos[MAXN + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1] * 2;
        dp[i] %= MOD;
        int &p = pos[a[i - 1]];
        if (p != 0){
            dp[i] -= dp[p - 1];
            dp[i] %= MOD;
        }
        p = i;
    }
    cout << (dp[n] - 1 + MOD) % MOD;
    return 0;
}