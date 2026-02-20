#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &p : a) cin >> p.first >> p.second;
    auto cmp = [](const auto &a, const auto &b){
        return a.second < b.second;
    };
    sort(all(a), cmp);
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        int l = a[i - 1].first;
        int r = a[i - 1].second;
        int w = r - l + 1;
        int pos = lower_bound(all(a), make_pair(0, l), cmp) - a.begin();
        // cerr << "pos : " << pos << endl;
        dp[i] = max(dp[i - 1], dp[pos] + w);
    }
    cout << dp[n];
    return 0;
}