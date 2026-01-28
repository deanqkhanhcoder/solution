#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
unordered_map<ll, pair<int, int>> f;
ll calc(ll x, int i, ll n){
    ll cur = 1;
    ll sum = 1;
    for (int j = 1; j <= i; j++){
        if (cur > n / x) return n + 1;
        cur *= x;
        if (sum > n - cur) return n + 1;
        sum += cur;
    }
    return sum;
}
void solve(ll n){
    pair<int, int> ans = {-1, -1};
    if (f.count(n)){
        ans = f[n];
        cout << ans.first << ' ' << ans.second << '\n';
        return;
    }
    bool ok = false;
    for (int i = 60; i >= 2; i--){
        int lo = 2, hi = pow(n, 1.0/i) + 100;
        while (lo <= hi){
            int mid = (lo + hi) / 2;
            ll sum = calc(mid, i, n);
            if (sum == n){
                ans = {mid, i};
                f[sum] = ans;
                ok = true;
                break;
            }
            else if (sum < n) lo = mid + 1;
            else hi = mid - 1;
        }
        if (ok){
            break;
        }
    }
    if (ok){
        cout << ans.first << ' ' << ans.second << '\n';
    } else {
        cout << -1 << '\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    while (q--){
        ll n; cin >> n;
        if (n < 7){
            cout << -1 << '\n';
            continue;
        }
        solve(n);
    }
    return 0;
}