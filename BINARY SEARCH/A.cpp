#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int MAXN = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "RIVER"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, M, j; cin >> n >> M >> j;
    vector<ll> pref(n, 1);
    for (int i = 1; i < n; ++i){
        pref[i] += pref[i - 1] + (1LL * i * i % M);
    }
    pref.insert(pref.begin(), 0);
    auto check = [&](ll mid){
        int cnt = 0;
        int idx = 0;
        while (idx < n){
            int nidx = upper_bound(pref.begin() + idx, pref.end(), pref[idx] + mid) - pref.begin() - 1;
            if (nidx == idx) return false;
            idx = nidx;
            cnt++;
            if (cnt > j) return false;
        }
        return cnt <= j;
    };
    ll lo = 0, hi = pref[n];
    for (int i = 1; i <= n; ++i) lo = max(lo, pref[i] - pref[i - 1]);
    while (lo < hi){
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
    return 0;
}