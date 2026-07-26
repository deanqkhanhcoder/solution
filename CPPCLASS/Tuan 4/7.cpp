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
    auto ceil_div = [](ll a, ll b){
        ll q = a / b;
        ll r = a % b;
        if (r && ((r > 0) == (b > 0))) q++;
        return q;
    };
    ll a, b, X; cin >> a >> b >> X;
    ll x, y;
    auto extended_gcd = [](auto &&self, ll a, ll b, ll &x, ll &y){
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
    ll g = extended_gcd(extended_gcd, a, b, x, y);
    if (X % g != 0){
        cout << -1 << endl;
        return 0;
    }
    ll mul = X / g;
    ll x_init = x * mul;
    ll y_init = -y * mul;
    ll k = max(ceil_div(-x_init, b / g), ceil_div(-y_init, a / g));
    x_init += k * (b / g);
    y_init += k * (a / g);
    if (x_init < 0 || y_init < 0){
        cout << -1;
        return 0;
    }
    cout << x_init + y_init << endl;
    return 0;
}