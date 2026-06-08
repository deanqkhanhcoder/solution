#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

struct point{
    int x, y;
    point(int x, int y) : x(x) , y(y) {}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    int n; cin >> n;
    vector<point> cow;
    for (int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        cow.emplace_back(x, y);
    }
    sort(all(cow), [](const point& a, const point& b){
        return a.y < b.y;
    });
    for (int i = 0; i < n; ++i){
        cow[i].y = i + 1;
    }
    sort(all(cow), [](const point& a, const point& b){
        return a.x < b.x;
    });
    for (int i = 0; i < n; ++i){
        cow[i].x = i + 1;
    }
    vector<vector<int>> area(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i){
        area[cow[i].x][cow[i].y] = 1;
    }
    vector<vector<ll>> pref(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            pref[i][j] = area[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    auto get = [&](int x1, int y1, int x2, int y2) -> ll {
        if (x1 > x2 || y1 > y2) return 0;
        return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
    };
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            int x1 = cow[i].x;
            int x2 = cow[j].x;
            int y1 = min(cow[i].y, cow[j].y);
            int y2 = max(cow[i].y, cow[j].y);
            ll upper = get(x1, y2, x2, n);
            ll lower = get(x1, 1, x2, y1);
            ans += upper * lower;
        }
    }
    cout << ans + 1;
    return 0;
}