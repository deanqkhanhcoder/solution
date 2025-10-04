#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = (int) 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;

    vector<pair<int,int>> qs(t);
    int maxest = 0;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        qs[i] = {n, k};
        maxest = max(maxest, k);
    }

    vector<vector<int>> dp(10, vector<int>(maxest + 1, 1));
    for (int k = 1; k <= maxest; ++k) {
        for (int d = 0; d <= 8; ++d) {
            dp[d][k] = dp[d+1][k-1];
            if (dp[d][k] >= MOD) dp[d][k] -= MOD;
        }
        dp[9][k] = ((ll)dp[0][k-1] + dp[1][k-1]) % MOD;
    }
    for (auto &q : qs) {
        int n = q.first;
        int k = q.second;
        ll ans = 0;
        while (n > 0) {
            int d = n % 10;
            ans += dp[d][k];
            if (ans >= MOD) ans -= MOD;
            n /= 10;
        }
        cout << ans % MOD << '\n';
    }

    return 0;
}
