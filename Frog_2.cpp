#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; ++i){
        for (int j = max(0, i - k); j < i; ++j){
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n - 1];
    return 0;
}