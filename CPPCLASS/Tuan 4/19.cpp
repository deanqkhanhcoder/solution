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
    auto extended_gcd = [&](auto &&self, int a, int b, ll &x, ll &y){
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
    while (t--){
        int l, s, k; cin >> l >> s >> k;
        int c = l - s;
        ll x, y;
        int g = extended_gcd(extended_gcd, k, l, x, y);
        if (c % g != 0){
            cout << -1 << endl;
            continue;
        }
        int mul = c / g;
        x *= mul;
        int step = l / g;
        x = (x % step + step) % step;
        cout << x << endl;
    }
    return 0;
}