#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
using i128 = __int128_t;

ll ans(ll a, ll b, ll mod) {
    return (i128)a * b % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << ans(a, b, c);
}