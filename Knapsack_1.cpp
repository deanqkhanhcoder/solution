#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<pair<int, int>> a(n);
    int sum = 0;
    for (auto &e : a){
        cin >> e.first >> e.second;
        sum += e.second;
    }
    vector<ll> dp(sum + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < n ; ++i){
        for (int j = sum; j >= a[i].second; --j) {
            if (dp[j - a[i].second] != LLONG_MAX) {
                dp[j] = min(dp[j], dp[j - a[i].second] + a[i].first);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= sum; ++i) {
        if (dp[i] <= w) ans = i;
    }

    cout << ans;
    return 0;
}