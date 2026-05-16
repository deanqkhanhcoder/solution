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
struct point{
    int x1, y1, x2, y2;
    point() {}
    point(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    bool operator>(const point &o) const{
        return x2 > o.x2;
    }
    int area(){
        int w = x2 - x1;
        int h = y2 - y1;
        int s = w * h;
        return s;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector<point> pos(3);
    for (int i = 0; i < 3; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pos[i] = point(x1, y1, x2, y2);
    }
    point &car = pos[2];
    auto overlap = [](const point &a, const point &b) -> int {
        pair<int, int> lenx = {max(a.x1, b.x1), min(a.x2, b.x2)};
        pair<int, int> leny = {max(a.y1, b.y1), min(a.y2, b.y2)};
        int w = max(0, lenx.second - lenx.first);
        int h = max(0, leny.second - leny.first);
        int s = w * h;
        return s;
    };
    auto p_overlap = [](const point &a, const point &b) -> point {
        pair<int, int> lenx = {max(a.x1, b.x1), min(a.x2, b.x2)};
        pair<int, int> leny = {max(a.y1, b.y1), min(a.y2, b.y2)};
        int x1 = lenx.first;
        int y1 = leny.first;
        int x2 = lenx.second;
        int y2 = leny.second;
        point o = point(x1, y1, x2, y2);
        return o;
    };
    if (pos[0] > pos[1]){
        swap(pos[0], pos[1]);
    }
    int s_overlap = overlap(pos[0], pos[1]);
    if (s_overlap == 0){
        int o1 = overlap(car, pos[0]);
        int o2 = overlap(car, pos[1]);
        int s1 = pos[0].area();
        int s2 = pos[1].area();
        cout << s1 - o1 + s2 - o2;
        return 0;
    } else {
        int s1 = pos[0].area();
        int s2 = pos[1].area();
        int s_cur = s1 + s2 - s_overlap;
        int o1 = overlap(car, pos[0]);
        int o2 = overlap(car, pos[1]);
        point lack = p_overlap(pos[0], pos[1]);
        int o3 = overlap(car, lack);
        int ans = s_cur - o1 - o2 + o3;
        cout << ans;
        return 0;
    }
}