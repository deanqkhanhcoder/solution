#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    ll n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    const int MASK = 1 << n;
    auto solve = [&](ll limit) -> ll {
        if (limit == 0) return 0;
        auto get_lcm = [](ll a, ll b, ll limit){
            ll g = gcd(a, b);
            a /= g;
            if (a > limit / b) return limit + 1;
            return a * b;
        };
        ll res = 0;
        for (int mask = 1; mask < MASK; ++mask){
            ll lcm = 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i){
                if ((mask >> i) & 1){
                    lcm = get_lcm(lcm, a[i], limit);
                    if (lcm == limit + 1) break;
                    cnt++;
                }
            }
            if (lcm == limit + 1) continue;
            if (cnt & 1) res += limit / lcm;
            else res -= limit / lcm;
        } 
        ll ans = limit - res;
        return ans;
    };
    ll ans = solve(r) - solve(l - 1);
    cout << ans << endl;
    return 0;
}