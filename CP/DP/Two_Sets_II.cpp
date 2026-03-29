#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int sum = n*(n + 1)/2;
    if (sum & 1){
        cout << 0;
        return 0;
    }
    sum >>= 1;
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i){
        for (int x = 0; x < i; ++x) dp[i][x] = dp[i-1][x];
        for (int x = i; x <= sum; ++x){
            dp[i][x] = (dp[i-1][x] + dp[i-1][x-i]) % MOD;
        }
    }
    cout << dp[n - 1][sum];
    return 0;
}