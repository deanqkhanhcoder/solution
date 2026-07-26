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
    int n; cin >> n;
    vector<int> a(n), m(n);
    ll M = 1;
    for (int i = 0; i < n; ++i){
        cin >> a[i] >> m[i];
        a[i] = (a[i] % m[i] + m[i]) % m[i];
        M *= m[i];
    }
    auto mod_inverse = [](ll a, ll m){
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
        ll x, y;
        ll g = extended_gcd(extended_gcd, a, m, x, y);
        x %= m;
        if (x < 0) x += m;
        return x;
    };
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        ll Mi = M / m[i];
        ll Ni = mod_inverse(Mi, m[i]);
        ll step = (a[i] * Mi % M) % M;
        step = (step * Ni % M) % M;
        ans = (ans + step) % M;
    }
    ans = (ans % M + M) % M;
    cout << ans << endl;
    return 0;
}