#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int> &x, const pair<int,int> &y){
    return x.second < y.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &e : a) cin >> e.first >> e.second;
    sort(a.begin(), a.end(), cmp);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        int l = a[i - 1].first, r = a[i - 1].second;
        int w = r - l + 1;
        int j = upper_bound(a.begin(), a.begin() + i - 1, make_pair(0, l - 1), cmp) - a.begin();
        dp[i] = max(dp[i - 1], dp[j] + w);
    }
    cout << dp[n];
    return 0;
}