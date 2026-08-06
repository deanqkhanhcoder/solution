#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MAXN = 4;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int t; cin >> t;
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
    auto mod_inverse = [&](ll a, ll b){
        ll x, y;
        ll g = extended_gcd(extended_gcd, a, b, x, y);
        assert(g == 1);
        return (x % b + b) % b;
    };
    while(t--){
        vector<int> a(MAXN), mod(MAXN);
        ll M = 1;
        for (int i = 0; i < MAXN; ++i){
            cin >> mod[i] >> a[i];
            M *= mod[i];
        }
        bool flag = false;
        for (int i = 0; i < MAXN; ++i){
            for (int j = i + 1; j < MAXN; ++j){
                if (__gcd(mod[i], mod[j]) != 1){
                    cout << -1 << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) continue;
        ll ans = 0;
        for (int i = 0; i < MAXN; ++i){
            ll Mi = M / mod[i];
            ll Ni = mod_inverse(Mi, mod[i]);
            ll term = (a[i] * Mi % M) % M;
            term = (term * Ni % M) % M;
            ans = (ans + term) % M;
        }
        cout << ans << endl;
    }
    return 0;
}
