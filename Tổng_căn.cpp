#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    ll res;
    for (int i = (int)sqrt(a); i <= (int)sqrt(b); ++i){
        ll l = max(a, (ll)i*i);
        ll r = min(b, (ll)(i+1)*(i+1) - 1);
        res += i * (r - l + 1);
    }
    cout << res;
    return 0;
}
