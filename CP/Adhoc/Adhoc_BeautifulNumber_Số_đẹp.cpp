#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll f(int mid){
    return mid/3 + mid/5 + mid/7 - mid/15 - mid/21 - mid/35 + mid/105;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; cin >> k;
    ll lo = 0;
    ll hi = (ll)1e18;
    ll ans = 0;
    while (lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        if (f(mid) >= k){
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ans;
    return 0;
}