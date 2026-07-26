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
using i128 = __int128;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    ll a, b, c, m; cin >> a >> b >> c >> m;
    auto bin_pow = [](ll a, ll b, ll mod){
        a %= mod;
        ll res = 1;
        while (b){
            if (b & 1) res = (i128)res * a % mod;
            a = (i128)a * a % mod;
            b >>= 1;
        }
        return res;
    };
    ll first = bin_pow(a, b, m);
    auto extended_gcd = [&](auto && self, ll a, ll b, i128 &x, i128 &y){
        if (b == 0){
            x = 1;
            y = 0;
            return a;
        }
        i128 x1, y1;
        ll d = self(self, b, a % b, x1 , y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return d;
    };
    i128 x, y;
    ll g = extended_gcd(extended_gcd, c, m, x, y);
    ll second = (x % m + m) % m;
    ll ans = (i128)first * second % m;
    cout << ans << endl;
    return 0;
}