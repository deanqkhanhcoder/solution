#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr ll INF = (ll)4e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<ll, ll>> box(n);
    for (int i = 0; i < n; ++i) cin >> box[i].first;
    for (int i = 0; i < n; ++i) cin >> box[i].second;
    sort(box.begin(), box.end(), [](auto &a, auto &b){
        return a.first + a.second < b.first + b.second;
    });
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        ll w = box[i - 1].first;
        ll c = box[i - 1].second;
        for (int k = i; k >= 1; k--){
            if (dp[k - 1] <= c){
                dp[k] = min(dp[k], dp[k - 1] + w);
                ans = max(ans, k);
            }
        }
    }
    cout << ans;
    return 0;
}