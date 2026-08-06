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
    string s; cin >> s;
    int n = s.length();
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    vector<int> cnt(26, 0);
    for (char c : s){
        cnt[c - 'a']++;
    }
    ll first = fact[n];
    ll second = 1;
    for (int c = 0; c < 26; ++c) second = (second * fact[cnt[c]]) % MOD;
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
    auto mod_inverse = [&](ll n){
        return bin_pow(n, MOD - 2);
    };
    cout << (first * mod_inverse(second)) % MOD << endl;
    return 0;
}