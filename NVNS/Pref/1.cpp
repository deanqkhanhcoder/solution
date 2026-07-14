#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, S; cin >> n >> S;
    int x, y; cin >> x >> y;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    /*
    S = 1/2(a[j] - a[i])*h
    1/2(a[j] - a[i])*h > S
    (a[j] - a[i]) * h > S * 2
    a[j] - a[i] >= 2 * s / h + 1
    a[j] >= 2 * s / h + 1 + a[i];
    */
    sort(all(a));
    ll T = (2LL * S) / y + 1;
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        int idx = lower_bound(a.begin() + i + 1, a.end(), a[i] + T) - a.begin();
        ans += n - idx;
    }
    cout << ans << endl;
    return 0;
}