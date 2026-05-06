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
struct optimal{
    int a;
    int b;
    int diff;
    optimal() {}
    bool operator<(const optimal &o) const{
        return diff < o.diff;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<optimal> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i].a;
    }
    for (int i = 0; i < n; ++i){
        cin >> v[i].b;
    }
    vector<int> C(q);
    for (int i = 0; i < q; ++i){
        cin >> C[i];
    }
    for (int i = 0; i < n; ++i){
        v[i].diff = v[i].b - v[i].a;
    }
    sort(all(v));
    vector<ll> prefa(n + 1);
    vector<ll> prefb(n + 1);
    prefa[0] = prefb[0] = 0;
    for (int i = 1; i <= n; ++i){
        prefa[i] = prefa[i - 1] + v[i - 1].a;
        prefb[i] = prefb[i - 1] + v[i - 1].b;
    }
    auto querya = [&](int l, int r) -> ll{
        if (l > r) return 0;
        return prefa[r] - prefa[l - 1];
    };
    auto queryb = [&](int l, int r) -> ll{
        if (l > r) return 0;
        return prefb[r] - prefb[l - 1];
    };
    for (int i = 0; i < q; ++i){
        auto it = upper_bound(all(v), C[i], [](int val, const optimal &o){
            return val < o.diff;
        });
        int idx = it - v.begin();
        ll S_a = querya(1, idx); 
        ll S_b = queryb(idx + 1, n); 
        int cnt = n - idx;
        ll ans = S_a + S_b - 1LL * cnt * C[i];
        cout << ans << endl;
    }
    return 0;
}
