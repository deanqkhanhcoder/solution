#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int &v : c) cin >> v;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        int ways = 0;
        for (int coin : c) {
            if (i >= coin) {
                ways += dp[i - coin];
                if (ways >= MOD) ways -= MOD;
            }
        }
        dp[i] = ways;
    }
    cout << dp[x];
    return 0;
}
