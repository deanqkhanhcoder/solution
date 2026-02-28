#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;
constexpr int LIMIT = (int)1e6;
bitset<LIMIT + 1> ip;
vector<int> pr;
vector<int> pref;
void pre(){
    ip.set();
    pr.reserve(LIMIT);
    ip[0] = ip[1] = 0;
    for (int i = 2; i <= LIMIT; ++i){
        if (ip[i]) pr.push_back(i);
        for (int &p : pr){
            if (1LL * i * p > LIMIT) break;
            ip[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    pref.resize(LIMIT + 1);
    pref[0] = pref[1] = 0;
    for (int i = 2; i <= LIMIT; ++i){
        pref[i] = pref[i - 1] + ip[i]; 
    }
    return;
}
int total(int l, int r){
    if (l > r || r < 2) return 0;
    l = max(2, l);
    return pref[r] - pref[l - 1];
}
ll lim(int pow, ll n){
    ll l = 0, r = n;
    while (l < r){
        ll mid = (l + r + 1) / 2;
        ll ans = 1;
        for (int i = 1; i <= pow; ++i){
            if (ans > n / mid){
                ans = n + 1;
                break;
            }
            ans *= mid;
        }
        if (ans <= n) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    int a, b; cin >> a >> b;
    pre();
    ll ans = 0;
    for (int d = a; d <= b; ++d){
        if (d == 2){
            ll hi = lim(2, n);
            ans += total(2, hi);
        } else if (d == 3){
            ll hi = lim(3, n);
            ans += total(2, hi);
        } else if (d == 5){
            ll hi = lim(5, n);
            ans += total(2, hi);
        } else if (d == 4){
            ll hi = lim(4, n);
            ans += total(2, hi);
            for (int &p1 : pr){
                ll p1_2 = (ll)p1 * p1;
                if (p1_2 > n / 4) break;
                int lp2 = sqrt(n / p1_2);
                if (lp2 < 2) break;
                ans += total(p1 + 1, lp2);
            }
        } else if (d == 6) {
            int hi = lim(6, n);
            ans += total(2, hi);
            for (int &p1 : pr){
                ll p1_3 = (ll)p1 * p1 * p1;
                if (p1_3 > n / 4) break;
                int lp2 = sqrt(n / p1_3);
                if (lp2 < 2) break;
                ans += total(p1 + 1, lp2);
                ans += total(2, min(p1 - 1, lp2));
            }
        }
    }
    cout << ans;
    return 0;
}