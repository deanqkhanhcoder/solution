#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;
using ll = long long;

struct pos {
    int p, t, d;
    pos() {}
    pos(int p, int t, int d) : p(p), t(t), d(d) {}
};

int n;
vector<pos> a;

ll f(ll x) {
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll dis = abs(x - a[i].p);
        if (dis > a[i].d) {
            res += (dis - a[i].d) * a[i].t;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.resize(n);
    ll low = 2e9, high = -2e9;
    for (int i = 0; i < n; ++i) {
        int p, t, d; cin >> p >> t >> d;
        a[i] = pos(p, t, d);
        low = min(low, (ll)p);
        high = max(high, (ll)p);
    }
    ll ans = 1e18;
    while (high - low > 3) {
        ll m1 = low + (high - low) / 3;
        ll m2 = high - (high - low) / 3;
        ll f1 = f(m1);
        ll f2 = f(m2);
        if (f1 < f2) high = m2;
        else low = m1;
    }
    for (ll x = low; x <= high; ++x) ans = min(ans, f(x));
    cout << ans << endl;
    return 0;
}