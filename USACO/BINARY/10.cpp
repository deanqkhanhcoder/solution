#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;

struct person {
    ll a, b, c;
};

ll floor_div(ll a, ll b){
    ll q = a / b;
    ll r = a % b;
    if (r && ((r > 0) != (b > 0))) q--;
    return q;
}

ll celi_div(ll a, ll b){
    ll q = a / b;
    ll r = a % b;
    if (r && ((r > 0) == (b > 0))) q++;
    return q;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--){
        int n; ll tc, tm; 
        cin >> n >> tc >> tm;
        vector<person> a(n);
        for (auto &p : a) cin >> p.a >> p.b >> p.c;
        auto check = [&](ll t) -> bool{
            /*
            1) 1 <= x <= tc
            1 <= y <= tm
            1 <= t - x <= tm
            tm <= x - t <= 1
            t - tm <= x <= t - 1
            */
            ll l = max(1LL, t - tm);
            ll r = min(tc, t - 1);
            if (l > r) return false;
            for (int i = 0; i < n; ++i){
                ll fi = a[i].a - a[i].b;
                ll se = a[i].c - a[i].b * t;
                if (fi == 0){
                    if (se < 0) return false;
                } else if (fi < 0) {
                    l = max(l, celi_div(se, fi));
                } else if (fi > 0) {
                    r = min(r, floor_div(se, fi));
                }
                if (l > r) return false;
            }
            return true;
        };
        ll lo = 2, hi = tc + tm;
        while (lo < hi){
            ll mid = (hi + lo + 1) / 2;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        ll ans = (tc + tm) - lo;
        cout << ans << endl;
    }
    return 0;
}