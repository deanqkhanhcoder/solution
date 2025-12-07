#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int LIM = 1e7;
ll dp[LIM + 1];
map<ll, ll> mp;

ll f(ll x) {
    if (x == 0) return 0;
    if (x <= LIM && dp[x]) return dp[x];
    if (x > LIM && mp.count(x)) return mp[x];
    ll res = max(x, f(x/2) + f(x/3) + f(x/4));
    if (x <= LIM) dp[x] = res;
    else mp[x] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        cout << f(x) << '\n';
    }
}
