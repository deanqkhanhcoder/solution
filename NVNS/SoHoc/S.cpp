#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main() {
    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    ll ans = LLONG_MAX;

    vector<pair<ll, ll>> r1 = {{a1, b1}, {b1, a1}};
    vector<pair<ll, ll>> r2 = {{a2, b2}, {b2, a2}};

    for (auto [x1, y1] : r1) {
        for (auto [x2, y2] : r2) {
            ll w = x1 + x2;
            ll h = max(y1, y2);
            ll s = max(w, h);
            ans = min(ans, s);
            w = max(x1, x2);
            h = y1 + y2;
            s = max(w, h);
            ans = min(ans, s);
        }
    }
    cout << ans * ans << endl;
}