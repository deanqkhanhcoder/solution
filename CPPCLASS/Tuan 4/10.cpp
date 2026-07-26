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
    auto floor_div = [](ll a, ll b){
        ll q = a / b;
        ll r = a % b;
        if (r && ((r > 0) != (b > 0))) q--;
        return q;
    };
    int a, b, c; cin >> a >> b >> c;
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
    ll x, y;
    int g = extended_gcd(extended_gcd, a, b, x , y);
    if (c % g != 0){
        cout << 0 << endl;
        return 0;
    }
    ll mul = c / g;
    ll x_init = 1LL * x * mul;
    ll y_init = 1LL * y * mul;
    ll l = ceil_div(1 - x_init, b / g);
    ll r = floor_div(y_init - 1, a / g);
    if (l > r){
        cout << 0 << endl;
        return 0;
    }
    cout << r - l + 1 << endl;
    return 0;
}