#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    vector<ll> prefix(k + 1, 1);
    for (int i = 1; i <= n; ++i){
        prefix[0] = dp[i-1][0];
        for (int j = 0; j <= k; ++j){
            if (j > 0) prefix[j] = (prefix[j-1] + dp[i-1][j]) % MOD;
            int low = j - a[i];
            if (low >= 1) dp[i][j] = (prefix[j] - prefix[low-1] + MOD) % MOD;
            else dp[i][j] = prefix[j];
        }
    }
    cout << dp[n][k] % MOD << "\n";
}
