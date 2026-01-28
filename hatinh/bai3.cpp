#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
// constexpr int INF = (int)1e9;
constexpr ll NEG = (ll)-1e18;
int main(){
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    int x, y, z;
    cin >> x >> y >> z;
    if (n < 3){
        cout << 0;
        return 0;
    }
    vector<int> prmax(n);
    vector<int> prmin(n);
    prmax[0] = prmin[0] = a[0];
    for (int i = 1; i < n; ++i){
        prmax[i] = max(a[i], prmax[i - 1]);
        prmin[i] = min(a[i], prmin[i - 1]);
    }
    vector<int> sufmax(n);
    vector<int> sufmin(n);
    sufmax[n - 1] = sufmin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i){
        sufmax[i] = max(a[i], sufmax[i + 1]);
        sufmin[i] = min(a[i], sufmin[i + 1]);
    }
    ll ans = NEG;
    // for (int i = 0; i < n; ++i){
    //     cout << maxpr[i] << ' ';
    // }
    for (int i = 1; i < n - 1; ++i){
        ll mid = (ll)y*a[i];
        ans = max(ans, (ll)x*prmax[i - 1] + mid + (ll)z*sufmax[i + 1]);
        ans = max(ans, (ll)x*prmin[i - 1] + mid + (ll)z*sufmax[i + 1]);
        ans = max(ans, (ll)x*prmax[i - 1] + mid + (ll)z*sufmin[i + 1]);
        ans = max(ans, (ll)x*prmin[i - 1] + mid + z*sufmin[i + 1]);
    }
    cout << ans;
}
