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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, m; cin >> n >> m;
    ll first = 1;
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        first = (first * a) % m;
    }
    ll second = 1;
    for (int i = 0; i < n; ++i){
        int b; cin >> b;
        second = (second * b) % m;
    }
    auto bin_pow = [](ll a, ll b, ll m){
        a %= m;
        ll res = 1;
        while (b){
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    };
    auto mod_inverse = [&](ll n){
        return bin_pow(n, m - 2, m);
    };
    cout << (first * mod_inverse(second)) % m << endl;
    return 0;
}