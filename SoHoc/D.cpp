#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, k; ll m; cin >> n >> m >> k;
    vector<int> a(n);
    auto poww = [&](int a, ll b, int m){
        a %= m;
        int res = 1;
        while (b > 0){
            if (b & 1) res = 1LL * res * a % m;
            a = (1LL * a * a) % m;
            b >>= 1;
        }
        return res;
    };
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        int res = 0;
        for (char c : s){
            res = (res * 10 + (c - '0')) % k;
        }
        a[i] = poww(res, m, k);
    }
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
    unordered_map<int, int> mp;
    mp.reserve(2 * n);
    mp.max_load_factor(0.7);
    mp[0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        int mod = pref[i] % k;
        cerr << "mod : " << mod << endl;
        ans += mp[mod];
        mp[mod]++;
    }
    cout << ans;
    return 0;
}