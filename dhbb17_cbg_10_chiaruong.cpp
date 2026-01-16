#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<ll> dp(s + 1, 0);
    vector<char> ok(s + 1, 0);
    dp[0] = 1;
    ok[0] = 1;
    for (int i = 0; i < n; ++i){
        int w = a[i];
        for (int j = s; j >= w; --j){
            if (ok[j - w]){
                ok[j] = 1;
                dp[j] += dp[j - w];
                if (dp[j] > MOD) dp[j] %= MOD;
            }
        }
    }
    for (int i = s; i >= 1; --i){
        if (ok[i]){
            cout << i << '\n';
            cout << dp[i] % MOD << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}