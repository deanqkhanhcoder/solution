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
    ll n; int a, b, c;
    cin >> n >> a >> b >> c;
    auto lcm = [](ll a, ll b, ll limit) -> ll {
        ll g = __gcd(a, b);
        if (a / g > limit / b) return limit + 1;
        ll res = a / g * b;
        return (res > limit ? limit + 1 : res);
    };
    ll f = n / a;
    ll s = n / b;
    ll t = n / c;
    ll lcmab = lcm(a, b, n);
    ll fs = n / lcmab;
    ll st = n / lcm(b, c, n);
    ll ft = n / lcm(a, c, n);
    ll fst = n / lcm(lcmab, c, n);
    ll ans = f + s + t - fs - st- ft + fst;
    cout << ans << endl;
    return 0;
}