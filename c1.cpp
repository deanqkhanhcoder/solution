#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <vector> 
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    n--;
    m--;
    ll s = (n + 1)/2;
    ll u = s*(s + 1);
    if (n % 2 != 0) u -= s;
    if (n < 0) u = 0;
    ll v = 0;
    ll limit = sqrt(m);
    for (ll k = 0; k <= limit; ++k){
        ll l = k * k + 1;
        ll r = (k + 1)*(k + 1);
        if (l > m) break;
        r = min(r, m);
        ll cnt = r - l + 1;
        v += (ll)k * cnt;
    }
    cout << u + v;
    return 0;
}