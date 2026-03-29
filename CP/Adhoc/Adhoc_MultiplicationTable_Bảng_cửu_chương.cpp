#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
int n, m;
ll k;
bool check(ll mid){
    ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        cnt += min((ll)m, mid/i);
        if (cnt >= k) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    ll lo = 1;
    ll hi = (ll)1e12;
    while (lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
}