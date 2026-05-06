
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    ll n; cin >> n;
    auto odd = [](ll n){
        return (n + 1) / 2;
    };
    auto even = [](ll n){
        return n / 2;
    };
    ll maxe = n / 2;
    ll lo = 0, hi = n;
    while (lo < hi){
        ll k = (lo + hi) / 2;
        int cur_odd = odd(k);
        ll s_odd = 1LL * cur_odd * cur_odd;
        int cur_even = even(k);
        ll s_even = maxe * (maxe + 1) - 1LL* cur_even * (cur_even + 1);
        if (s_odd > s_even) hi = k;
        else lo = k + 1;
    }
    cout << lo;
    return 0;
}
