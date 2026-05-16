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
struct rect {
    int x1, y1, x2, y2;
    rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    int len_x() {
        return this->x2 - this->x1;
    }
    int len_y() {
        return this->y2 - this->y1;
    }
    static int cnt(const rect &a, const rect &b){
        pair<int, int> fi = {a.x1, a.y1};
        pair<int, int> se = {a.x1, a.y2};
        pair<int, int> th = {a.x2, a.y1};
        pair<int, int> fo = {a.x2, a.y2};
        auto check = [&](const pair<int, int> &point){
            return point.first >= b.x1 && point.first <= b.x2 && point.second >= b.y1 && point.second <= b.y2;
        };
        int ans = 0;
        if (check(fi)) ans++;
        if (check(se)) ans++;
        if (check(th)) ans++;
        if (check(fo)) ans++;
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	// freopen("billboard.in", "r", stdin);
	// freopen("billboard.out", "w", stdout);
    // code here
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    rect fi = rect(x1, y1, x2, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    rect se = rect(x1, y1, x2, y2);
    int cnt = rect::cnt(fi, se);
    int s_full = fi.len_x() * fi.len_y();
    if (cnt < 2){
        cout << s_full;
        return 0;
    } else if (cnt == 4){
        cout << 0;
        return 0;
    } else {
        int x_overlap = max(0, min(fi.x2, se.x2) - max(fi.x1, se.x1));
        int y_overlap = max(0, min(fi.y2, se.y2) - max(fi.y1, se.y1));
        int s = x_overlap * y_overlap;
        cout << s_full - s;
        return 0;
    }
}