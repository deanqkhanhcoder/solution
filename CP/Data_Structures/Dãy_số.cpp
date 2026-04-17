#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &e : a) cin >> e;
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i){
        pref[i] = pref[i - 1] + a[i - 1];
    }
    ll sums = pref[n];
    vector<ll> mins(n + 1);
    vector<ll> minp(n + 1);
    mins[n] = pref[n];
    minp[1] = pref[1];
    for (int i = n - 1; i >= 1; --i) mins[i] = min(mins[i + 1], pref[i]);
    for (int i = 2; i <= n; ++i) minp[i] = min(minp[i - 1], pref[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        ll rem = pref[i - 1];
        ll minf = mins[i];
        if (minf <= rem) continue;
        if (i - 1 == 0){
            ans++;
            continue;
        } 
        rem -= sums;
        ll minsec = minp[i - 1];
        if (minsec <= rem) continue;
        ans++;
    }
    cout << ans;
    return 0;
}