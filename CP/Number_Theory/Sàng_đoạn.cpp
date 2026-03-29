#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void segmentedSieve(ll l, ll r) {
    vector<bool> f(r - l + 1, true);
    for (ll i = 2; i * i <= r; ++i) {
        ll start = max(i * i, ((l + i - 1) / i) * i);
        for (ll j = start; j <= r; j += i) {
            f[j - l] = false;
        }
    }
    for (ll i = max(2LL, l); i <= r; ++i) {
        if (f[i - l]) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    segmentedSieve(l, r);
    return 0;
}
