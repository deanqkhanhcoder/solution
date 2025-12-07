#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d; cin >> n >> d;
    vector<ll> cnt(d, 0);
    ll pref = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        pref = (pref + x) % d;
        if (pref < 0) pref += d;
        cnt[pref]++;
    }
    ll ans = 0;
    for (int r = 0; r < d; ++r) {
        ans += cnt[r] * (cnt[r] - 1) / 2;
    }
    cout << ans;
    return 0;
}
