#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <vector>
using namespace std;
using ll = long long;
constexpr ll NEG = (ll)-1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    ll ans = NEG;
    for (int sh = -n + 1; sh <= n - 1; ++sh){
        int l, r, len;
        if (sh >= 0) {
            l = sh;
            r = 0;
            len = n - sh;
        } else {
            l = 0;
            r = -sh;
            len = n + sh;
        }
        ll cur = NEG;
        ll maxest = NEG;
        for (int i = 0; i < len; ++i){
            ll p = (ll)a[l + i] * b[r + i];
            cur = max(p, cur + p);
            maxest = max(maxest, cur);
        }
        ans = max(ans, maxest);
    }
    cout << ans;
}