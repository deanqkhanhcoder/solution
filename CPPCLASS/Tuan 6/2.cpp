#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; ++i){
        for (int j = max(0, i - k); j < i; ++j){
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}