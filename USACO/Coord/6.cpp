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
constexpr int INF = (int)1e9;
constexpr ll LLINF = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "split"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    int min_x = INF, min_y = INF, max_x = 0, max_y = 0; 
    for (pair<int, int> &p : a){
        cin >> p.first >> p.second;
        min_x = min(min_x, p.first);
        min_y = min(min_y, p.second);
        max_x = max(max_x, p.first);
        max_y = max(max_y, p.second);
    } 
    ll total = 1LL * (max_x - min_x) * (max_y - min_y);
    // cerr << "total : " << total << endl;
    auto check = [&]{
        vector<pair<int, int>> suf_r(n);
        suf_r[n - 1].first = a[n - 1].second;
        suf_r[n - 1].second = a[n - 1].second;
        for (int i = n - 2; i >= 0; --i){
            suf_r[i].first = min(suf_r[i + 1].first, a[i].second);
            suf_r[i].second = max(suf_r[i + 1].second, a[i].second);
        }
        ll res = LLINF;
        int min_l = INF, max_l = 0;
        for (int i = 0; i < n - 1; ++i){
            min_l = min(min_l, a[i].second);
            max_l = max(max_l, a[i].second);
            ll s1 = 1LL * (max_l - min_l) * (a[i].first - a[0].first);
            ll s2 = 1LL * (suf_r[i + 1].second - suf_r[i + 1].first) * (a[n - 1].first - a[i + 1].first);
            res = min(res, s1 + s2);
        }
        return res;
    };
    sort(all(a));
    ll minest = check();
    for (int i = 0; i < n; ++i) swap(a[i].first, a[i].second);
    sort(all(a));
    minest = min(minest, check());
    // cerr << "minest = " << minest << endl;
    cout << total - minest << endl;
    return 0;
}