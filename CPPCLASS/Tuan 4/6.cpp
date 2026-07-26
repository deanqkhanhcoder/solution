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
constexpr int MAXA = (int)1e6;
constexpr int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    vector<int> spf(MAXA + 1, 0);
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
    auto bin_pow = [](int a, int b){
        a %= MOD;
        int res = 1;
        while (b){
            if (b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    };
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e; 
        vector<int> exp(MAXA + 1, 0);
        for (int e : a) {
            while (e > 1){
                int p = spf[e];
                int cnt = 0;
                while (e % p == 0){
                    e /= p;
                    cnt++;
                }
                exp[p] = max(exp[p], cnt);
            }
        }
        int ans = 1;
        for (int i = 2; i <= MAXA; ++i){
            if (exp[i] == 0) continue;
            if (exp[i] & 1) exp[i]++;
            ans = (1LL * ans * bin_pow(i, exp[i])) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}