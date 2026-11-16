#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    unordered_map<ll, ll> min_pref;
    min_pref.max_load_factor(0.7);
    ll pref = 0;
    ll ans = -INFLL;
    for (int i = 0; i < n; ++i) {
        ll prev_pref = pref;
        pref += a[i];
        if (min_pref.count(a[i])) {
            ans = max(ans, pref - min_pref[a[i]]);
            min_pref[a[i]] = min(min_pref[a[i]], prev_pref);
        } else {
            min_pref[a[i]] = prev_pref;
        }
    }
    cout << ans << '\n';
    return 0;
}