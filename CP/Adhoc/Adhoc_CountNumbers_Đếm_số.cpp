#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
using i128 = __int128_t;
const int MOD = (int)1e9 + 7;
ll binpow(ll a, ll b){
    ll res = 1;
    a %= MOD;
    while (b > 0){
        if (b & 1) res = ((i128)res * a) % MOD;
        a = ((i128)a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll cnt0 = n / 3;
    ll cnt1 = (n + 1) / 3;
    ll cnt2 = (n + 2) / 3;
    ll res = (i128)binpow(3, cnt1) * binpow(3, cnt2) % MOD * binpow(4, cnt0) % MOD;
    cout << res % MOD;
    return 0;
}