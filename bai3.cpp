#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll sum(vector<ll> &a) {
    if (a.size() <= 1) return 0;
    sort(a.begin(), a.end());
    ll pref = 0;
    ll res = 0;
    for (ll i = 0; i < (ll)a.size(); ++i) {
        res += a[i] * i - pref;
        pref += a[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    vector<vector<ll>> mix(m + 1);
    vector<ll> all = c;
    for (int i = 0; i < n; ++i) {
        mix[b[i]].push_back(c[i]);
    }

    ll t1 = sum(all);
    ll t2 = 0;
    for (int t = 1; t <= m; ++t) {
        if (!mix[t].empty()) t2 += sum(mix[t]);
    }
    cout << (t1 - t2) << '\n';
    return 0;
}
