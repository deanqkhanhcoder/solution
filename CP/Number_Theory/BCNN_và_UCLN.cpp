#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll u, v; cin >> u >> v;
    if (v % u != 0) {
        cout << 0;
        return 0;
    }
    ll k = v / u;
    int cnt = 0;
    for (ll i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            ++cnt;
            while (k % i == 0) k /= i;
        }
    }
    if (k > 1) ++cnt;
    cout << (1LL << cnt);
    return 0;
}
