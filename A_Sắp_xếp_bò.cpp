#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, K;
    cin >> n >> K;
    vector<ll> dp(n+1, 0);
    for (int i = 0; i <= min(n, K); i++) {
        dp[i] = i + 1;
    }
    for (int i = K+1; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-K-1];
    }

    cout << dp[n] << "\n";
    return 0;
}
