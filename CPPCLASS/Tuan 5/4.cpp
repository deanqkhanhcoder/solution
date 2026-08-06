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
    int n, k; cin >> n >> k;
    int R = n - k;
     /*
    C(R + k - 1, k - 1) = (R + 1) .. * (R + k - 1) / (1 .. * k - 1)
    */
    ll first = 1;
    ll second = 1;
    for (int i = 1; i <= k - 1; ++i){
        first = (first * (R + i)) % MOD;
        second = (second * i) % MOD;
    }
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
    auto mod_inverse = [&](ll val){
        return bin_pow(val, MOD - 2);
    };
    cout << (first * mod_inverse(second) % MOD) << endl;
    return 0;
}