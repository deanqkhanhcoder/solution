#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e6;
ll dp[MAX_N][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dp[i][1] = (2 * dp[i - 1][1] + dp[i - 1][0]) % MOD;
        dp[i][0] = (dp[i - 1][1] + 4 * dp[i - 1][0]) % MOD;
    }
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cout << ((ll)dp[n - 1][0] + dp[n - 1][1]) % MOD << "\n";
    }
    
    return 0;
}
