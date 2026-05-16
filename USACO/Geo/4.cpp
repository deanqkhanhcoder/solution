#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

struct rect {
    int x1, y1, x2, y2;
    rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    static rect intersect(const rect &a, const rect &b) {
        int nx1 = max(a.x1, b.x1);
        int ny1 = max(a.y1, b.y1);
        int nx2 = min(a.x2, b.x2);
        int ny2 = min(a.y2, b.y2);
        return rect(nx1, ny1, nx2, ny2);
    }
    ll area() const {
        ll w = max(0, x2 - x1);
        ll h = max(0, y2 - y1);
        return w * h;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    rect black(x1, y1, x2, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    rect white1(x1, y1, x2, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    rect white2(x1, y1, x2, y2);
    rect i1 = rect::intersect(black, white1);
    rect i2 = rect::intersect(black, white2);
    rect i12 = rect::intersect(i1, i2); 
    ll s_black = black.area();
    ll s_covered = i1.area() + i2.area() - i12.area();
    if (s_covered < s_black) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}