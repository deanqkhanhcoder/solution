#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
constexpr int MOD = 123456789;

inline int addmod(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline int submod(int a, int b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    if (k > n){
        cout << 0;
        return 0;
    }
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    static int endv[2001][2001] = {0};

    for (int i = 0; i < n; i++){
        int v = a[i];
        vector<int> pre = dp;
        for (int len = k; len >= 1; len--){
            int ca = pre[len - 1];
            int rem = endv[v][len];
            int ans = submod(ca, rem);
            endv[v][len] = addmod(endv[v][len], ans);
            dp[len] = addmod(dp[len], ans);
        }
    }
    cout << dp[k] % MOD;
}
