#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int &v : c) cin >> v;
    int dp[x + 1] = {0};
    dp[0] = 1;
    for (int coin : c) {
        for (int i = coin; i <= x; i++) {
            dp[i] += dp[i - coin];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    cout << dp[x];
    return 0;
}
