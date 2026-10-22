#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    /*
    u_n = u_(n - 1) * x;
    u_u = 1 * x ^ (n - 1);
    sum = (1 * (1 - x^n)) / 1 - x;
    */
    int x, n; cin >> x >> n;
    if (x == 1){
        cout << (n + 1) % MOD;
        return 0;
    }
    auto bin_pow = [](int a, int b){
        a %= MOD;
        if (a < 0) a += MOD;
        int res = 1;
        while (b){
            if (b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1; 
        }
        return res;
    };
    auto mod_inverse = [&](int val){
        return bin_pow(val, MOD - 2);
    };
    int first = (1 - bin_pow(x, n + 1) + MOD) % MOD;
    // cerr << "first = " << first << " bin_pow(x, n) = " << bin_pow(x, n) << endl;
    int second = mod_inverse(1 - x);
    cout << 1LL * first * second % MOD << endl;
    return 0;
}