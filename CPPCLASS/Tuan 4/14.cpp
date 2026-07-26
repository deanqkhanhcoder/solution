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
    int t; cin >> t;
    while (t--){
        int a, b, c; cin >> a >> b >> c;
        auto extended_gcd = [&](auto&& self, int a, int b, ll &x , ll &y){
            if (b == 0){
                x = 1;
                y = 0;
                return a;
            }
            ll x1, y1;
            int d = self(self, b, a % b, x1, y1);
            x = y1;
            y = x1 - (a / b) * y1;
            return d;
        };
        ll x, y;
        int g = extended_gcd(extended_gcd, a, b, x, y);
        if (c % g != 0){
            cout << -1 << endl;
            continue;
        }
        int mul = c / g;
        ll x_init = x * mul;
        ll y_init = y * mul;
        /*
        BAI TOAN KHAC
        x = x1 + kb / g
        y = y1 - ka / g
        Đặt b / g = B, a / g = A
        => x + y = x1 + y1 + k(B - A);
        Đặt S = x1 + y1, D = (B - a)
        Cần tối thiểu |S + Dk| = 0
        => k = -S / D
        */
        ll dx = b / g;
        ll dy = a / g;
        auto calc = [&](ll t) -> ll {
            ll X = x_init + dx * t;
            ll Y = y_init - dy * t;
            return llabs(X) + llabs(Y);
        };
        ll lo = -INF;
        ll hi = INF;
        while (hi - lo > 10){
            ll m1 = lo + (hi - lo) / 3;
            ll m2 = hi - (hi - lo) / 3;
            if (calc(m1) <= calc(m2)){
                hi = m2 - 1;
            } else {
                lo = m1 + 1;
            }
        } 
        ll best_val = calc(lo);
        for (ll t = lo + 1; t <= hi; ++t){
            ll cur = calc(t);
            best_val = min(best_val, cur);
        }
        cout << best_val << endl;
    }
    return 0;
}