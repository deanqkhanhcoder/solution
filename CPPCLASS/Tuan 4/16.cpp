#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    ll m, n; cin >> m >> n;
    vector<ll> a(n);
    ll s = 0;
    for (ll &e : a){
        cin >> e;
        s += e;
    }
    if (m < s){
        cout << 0 << endl;
        return 0;
    }
    ll R = m - s;
    // cerr << "R = " << R << endl;
    /*
    C(R + n - 1, n - 1) = (R + 1) .. * (R + n - 1) / (1 .. * n - 1)
    */
    auto bin_pow = [](ll a, ll b){
        a %= MOD;
        ll res = 1;
        while (b){
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    };
    auto mod_inverse = [&](ll n){
        return bin_pow(n, MOD - 2);
    };
    ll first = 1;
    ll second = 1;
    for (int i = 1; i <= n - 1; ++i){
        first = (first * ((R + i) % MOD)) % MOD;
        second = (second * i) % MOD;
    }
    ll ans = (first * mod_inverse(second)) % MOD;
    cout << ans << endl;
    return 0;
}