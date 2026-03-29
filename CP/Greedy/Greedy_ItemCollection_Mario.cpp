#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const ll NEG = (ll)-1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MARIO.INP", "r", stdin);
    freopen("MARIO.OUT", "w", stdout);
    int n, x, k; cin >> n >> x >> k;
    int st = 0;
    vector<pair<int, ll>> al;
    vector<pair<int, ll>> ar;
    al.reserve(n);
    ar.reserve(n);
    for (int i = 0; i < n; ++i){
        int a, w; cin >> a >> w;
        if (a < x) al.push_back({x - a, w});
        else if (a > x) ar.push_back({a - x, w});
        else {
            st += w;
        }
    }
    sort(al.begin(), al.end());
    sort(ar.begin(), ar.end());
    int nl = al.size(), nr = ar.size();
    for (int i = 1; i < nr; ++i) ar[i].second += ar[i - 1].second;
    for (int i = 1; i < nl; ++i) al[i].second += al[i - 1].second;
    ll ans = NEG;
    for (int i = 0; i < nr; ++i){
        ll cur = ar[i].second;
        ll t = (ll)k - 2LL*ar[i].first;
        if (t < 0) { 
            ans = max(ans, cur); 
            continue; 
        }
        auto it = upper_bound(al.begin(), al.end(), make_pair((int)t, INF),
            [](const pair<int,ll> &a, const pair<int,ll> &b){
                return a.first < b.first;
            });
        if (it == al.begin()) ans = max(ans, cur);
        else { 
            --it; 
            ans = max(ans, cur + it->second); 
        }
    }
    for (int i = 0; i < nl; ++i){
        ll cur = al[i].second;
        ll t = (ll)k - 2LL*al[i].first;
        if (t < 0) {
            ans = max(ans, cur); 
            continue;
        }
        auto it = upper_bound(ar.begin(), ar.end(), make_pair((int)t, INF),
            [](const pair<int,ll> &a, const pair<int,ll> &b){
                return a.first < b.first;
            });
        if (it == ar.begin()) ans = max(ans, cur);
        else { 
            --it; 
            ans = max(ans, cur + it->second); 
        }
    }
    ans += st;
    cout << ans;
    return 0;
}