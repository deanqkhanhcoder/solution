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
constexpr int MOD = (int)1e9 + 7;
struct query{
    int l, r;
    ll v;
    query() {}
    query(int l,int r, ll v) : l(l), r(r), v(v) {}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<query> qk[201];
    for (int i = 1; i <= q; ++i){
        int l, r, v, k; cin >> l >> r >> v >> k;
        qk[k].push_back(query(l, r, v));
    }
    auto binpow = [](int a, int b){
        int res = 1;
        while (b){
            if (b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    };
    auto inverse = [&](int k){
        return binpow(k, MOD - 2);
    };
    vector<ll> diff(n + 1, 0);
    vector<ll> correct(n + 1, 0);
    for (int k = 1; k <= 200; ++k){
        if (qk[k].empty()) continue;
        fill(all(diff), 0);
        int inversek = inverse(k);
        for (query &qry : qk[k]){
            int total = (1LL * qry.v * binpow(inversek, qry.l)) % MOD;
            diff[qry.l] = (diff[qry.l] + total) % MOD;
            if (qry.r + 1 <= n) diff[qry.r + 1] = (diff[qry.r + 1]  - total + MOD) % MOD;
        }
        ll curr = 0;
        ll kpowi = k;
        for (int i = 1; i <= n; ++i){
            curr = (curr + diff[i]) % MOD;
            int th = (1LL * curr * kpowi) % MOD;
            correct[i] = (correct[i] + th) % MOD;
            kpowi = (1LL * kpowi * k) % MOD;
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << correct[i] << ' ';
    }
    return 0;
}