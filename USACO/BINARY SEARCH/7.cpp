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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "socdist"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> a(m);
    for (pair<ll, ll> &p : a) cin >> p.first >> p.second;
    sort(all(a));
    auto check = [&](const ll D){
        auto put = [=](const ll a, const ll b){
            return (b - a) / D + 1;
        };
        auto maxest = [=](const ll a, const ll b){
            return b - (b - a) % D;
        };
        ll place = 0;
        ll conner = -1;
        for (int i = 0; i < m; ++i){
            ll l = a[i].first;
            ll r = a[i].second;
            if (conner != -1) l = max(l, conner + D);
            if (l > r) continue;
            place += put(l, r);
            if (place >= n) return true;
            conner = maxest(l, r);
        }
        return false;
    };
    ll lo = 1, hi = a.back().second - a[0].first;
    while(lo < hi){
        ll mid = (hi + lo + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo;
}