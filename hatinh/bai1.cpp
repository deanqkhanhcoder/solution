#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    freopen("BAI1.INP", "r", stdin);
    freopen("Bai1.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; ++i){
        ans += max(0LL, n/i - i);
    }
    cout << ans;
    return 0;
}
