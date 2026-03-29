#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CSBN.INP", "r", stdin);
    freopen("CSBN.OUT", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> cnt(b.size(), 0);
    ll ans = 0;
    for (int x : a) {
        int idx = lower_bound(b.begin(), b.end(), x) - b.begin();
        ans += cnt[idx];
        cnt[idx]++;
    }
    cout << ans;
}
