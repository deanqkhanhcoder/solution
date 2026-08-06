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
constexpr int MAXA = (int)1e5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, q; cin >> n >> q;
    vector<int> a(n, 1);
    vector<int> spf(MAXA, 0);
    vector<int> primes;
    for (int i = 2; i <= MAXA; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes){
            if (1LL * i * p > MAXA) break; 
            spf[i * p] = p;
            if (spf[i] == p) break;
        }
    }
    vector<vector<pair<int, int>>> factor(MAXA);
    for (int i = 2; i <= MAXA; ++i){
        int x = i;
        while (x > 1){
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0){
                x /= p;
                cnt++;
            }
            factor[i].push_back({p, cnt});
        }
    }
    vector<int> cnt(MAXA + 1, 0);
    ll ans = 1;
    auto bin_pow = [&](ll a, ll b){
        a %= MOD;
        int res = 1;
        while (b){
            if (b & 1) res = (1LL * res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    };
    auto mod_inverse = [&](ll val){
        return bin_pow(val, MOD - 2);
    };
    auto add = [&](int val){
        for (auto [p, e] : factor[val]){
            ans = (ans * mod_inverse(cnt[p] + 1)) % MOD;
            cnt[p] += e;
            ans = (ans * (cnt[p] + 1) % MOD);
        }
    };
    auto rem = [&](int val){
        for (auto [p, e] : factor[val]){
            ans = (ans * mod_inverse(cnt[p] + 1)) % MOD;
            cnt[p] -= e;
            ans = (ans * (cnt[p] + 1) % MOD);
        }
    };
    while (q--){
        int pos, val; cin >> pos >> val;
        pos--;
        rem(a[pos]);
        add(val);
        a[pos] = val;
        cout << ans << endl;
    }
    return 0;
}