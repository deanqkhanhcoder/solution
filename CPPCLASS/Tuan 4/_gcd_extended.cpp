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
    ll a, m; cin >> a >> m;
    auto extended_gcd = [&](auto &&self, ll a, ll b, ll &x, ll &y){
        if (b == 0){
            x = 1;
            y = 0;
            return a;
        }
        ll x1, y1;
        ll d = self(self, b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return d;
    };
    auto mod_inverse = [&](ll a, ll m) -> ll {
        ll x, y;
        ll g = extended_gcd(extended_gcd, a, m, x, y);
        if (g == 1){
            return (x % m + m) % m;
        } else {
            return -1;
        }
    };
    ll inv = mod_inverse(a, m);
    cout << inv << endl;
    return 0;
}