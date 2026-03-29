#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
using namespace std;
using ll = long long;
constexpr int MAXN = (int)1e6;
int n;
bitset<MAXN + 1> pr;

void sieve(){
    pr.set();
    pr[0] = pr[1] = 0;
    for (int i = 4; i <= n; i += 2) pr[i] = 0;
    for (int i = 3; i * i <= n; i += 2){
        if (pr[i]){
            for (int j = i * i; j <= n; j += 2 * i){
                pr[j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n < 2){
        cout << -1;
        return 0;
    }
    sieve();
    vector<ll> a(n);
    for (ll &e : a) cin >> e;
    ll s = 0;
    ll ans = LLONG_MIN;
    ll mres = LLONG_MAX;
    for (int i = 1; i <= n; ++i){
        s += a[i - 1];
        if (pr[i]){
            mres = min(mres, s - a[i - 1]);
            ans = max(ans, s - mres);
        }
    }
    cout << ans;
    return 0;
}