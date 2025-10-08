#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MAXA = 1e5;
const int MOD = 1e9 + 7;
using ll = long long;
vector<int> spf(MAXA + 1, 0);

void sieve() {
    for (int i = 2; i <= MAXA; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (int j = i * 2; j <= MAXA; j += i)
                if (spf[j] == 0) spf[j] = i;
        }
    }
}

ll powmod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> e(MAXA + 1, 0);
    for (int x : a) {
        while (x > 1) {
            int p = spf[x];
            int c = 0;
            while (x % p == 0) x /= p, c++;
            e[p] = max(e[p], c);
        }
    }

    ll ans = 1;
    for (int p = 2; p <= MAXA; ++p)
        if (e[p])
            ans = ans * powmod(p, e[p]) % MOD;
    cout << ans;
}
