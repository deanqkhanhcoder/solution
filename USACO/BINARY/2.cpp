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
struct point{
    int x, y, t;
    point(int x, int y, int t) : x(x), y(y), t(t) {}
    bool operator<(const point& o) const {
        return t < o.t;
    }
    static bool check(const point&a, const point&b){
        ll dist_X = 1LL * (a.x - b.x) * (a.x - b.x);
        ll dist_Y = 1LL * (a.y - b.y) * (a.y - b.y);
        ll time = 1LL * (a.t - b.t) * (a.t - b.t);
        return dist_X + dist_Y <= time;
    };
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    int g, n; cin >> g >> n;
    vector<point> a;
    for (int i = 0; i < g; ++i){
        int x, y, t; cin >> x >> y >> t;
        a.emplace_back(x, y, t);
    }
    sort(all(a));
    vector<point> b;
    for (int i = 0; i < n; ++i){
        int x, y, t; cin >> x >> y >> t;
        b.emplace_back(x, y, t);
    }
    auto lower = [](const point &a, auto it){
        it--;
        const point &b = *it;
        return point::check(a, b); 
    };
    auto upper = [](const point &a, auto it){
        const point &b = *it;
        return point::check(a, b); 
    };
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int this_t = b[i].t;
        auto it = lower_bound(all(a), (point){0, 0, this_t});
        if (it == a.end()){
            if (!lower(b[i], it)) ans++;
            continue;
        }
        if (it == a.begin()){
            if (!upper(b[i], it)) ans++;
            continue;
        }
        if (it->t == this_t){
            if (!point::check(b[i], *it)) ans++;
            continue;
        }
        if (!lower(b[i], it) || !upper(b[i], it)) ans++;
    }
    cout << ans;
}