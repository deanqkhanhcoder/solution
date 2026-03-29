#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;

ll lcm(ll x, ll y, ll n){
    ll g = gcd(x, y);
    if (x > n / (y / g)) return n + 1;
    return x * (y / g);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    int k; cin >> k;
    vector<ll> a(k);
    for (ll &e: a) cin >> e;
    int size = 1 << k;
    ll res = 0;
    for (int m = 1; m < size; ++m){
        bool over = false;
        ll clcm = 1;
        int cnt = 0;
        for (int j = 0; j < k; ++j){
            if (m & (1 << j)){
                cnt++;
                clcm = lcm(clcm, a[j], n);
                if (clcm > n) {over = true; break;}
            }
        }
        if (!over){
            ll p = n / clcm;
            if (cnt & 1) res += p;
            else res -= p;
        }
    }
    cout << res;
    return 0;
}