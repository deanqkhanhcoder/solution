#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;

constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, l, h; cin >> n >> k >> l >> h;
    ll new_n = n - k * l;
    ll m = h - l;
    if (new_n < 0 || m < 0 || new_n > m * k) {
        cout << 0 << endl;
        return 0;
    }
    auto mod_inverse = [&](ll x) {
        auto bin_pow = [&](ll a, ll b) {
            a %= MOD;
            ll res = 1;
            while (b > 0) {
                if (b & 1) res = (res * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
            }
            return res;
        };
        return bin_pow(x, MOD - 2);
    };
    ll LIMIT = new_n + k;
    vector<int> fact(LIMIT + 1);
    fact[0] = 1;
    for (int i = 1; i <= LIMIT; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    vector<int> inv(LIMIT + 1);
    inv[LIMIT] = mod_inverse(fact[LIMIT]);
    for (int i = LIMIT - 1; i >= 0; --i) {
        inv[i] = (1LL * inv[i + 1] * (i + 1)) % MOD;
    }
    auto calc = [&](ll a, ll b) -> int {
        if (b < 0 || b > a) return 0;
        return (1LL * fact[a] * inv[b] % MOD) * inv[a - b] % MOD;
    };

    ll ans = 0;
    ll range = min(k, new_n / (m + 1));
    for (ll j = 0; j <= range; ++j) {
        int ways1 = calc(k, j); 
        int ways2 = calc(new_n - j * (m + 1) + k - 1, k - 1);
        int total = (1LL * ways1 * ways2) % MOD;

        if (j % 2 == 0) {
            ans = (ans + total) % MOD;
        } else {
            ans = (ans - total + MOD) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}