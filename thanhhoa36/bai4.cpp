#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for (int &x : a) cin >> x;
    vector<int> d;
    for (int x : a) {
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (i <= n) d.push_back(i);
                int t = x / i;
                if (t != i && t <= n) d.push_back(t);
            }
        }
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int dv : d) {
            if (i - dv >= 1) {
                dp[i] += dp[i - dv];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] % MOD;
    return 0;
}
