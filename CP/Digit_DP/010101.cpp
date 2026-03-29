#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int n, k;
ll dp[65][130][101];
ll dfs(int idx, int bal, int modk){
    if (idx == n){
        return (bal == 0 && modk == 0);
    }
    if (bal < -n/2 || bal > n/2) return 0;
    ll &res = dp[idx][bal + 64][modk];
    if (res != -1) return res;
    res = 0;
    int one = (idx + bal) / 2;
    // one = idx - zero
    // one + one = idx + one - zero
    // 2one = idx + bal
    // one = (idx + bal) / 2
    int zero = idx - one;
    if (one + 1 <= n / 2){
        int nmod = (modk * 2 + 1) % k;
        res += dfs(idx + 1, bal + 1, nmod);
    }
    if (idx > 0 && zero + 1 <= n / 2){
        int nmod = (modk * 2) % k;
        res += dfs(idx + 1, bal - 1, nmod);
    }
    return res;
}
ll solve(){
    if (n % 2 || k == 0){
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    cout << solve();
}