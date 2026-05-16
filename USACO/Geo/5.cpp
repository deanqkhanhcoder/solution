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
struct rect{
    int x1, y1, x2, y2;
    rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    int w() const{
        return x2 - x1;
    }
    int h() const{
        return y2 - y1;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    int t; cin >> t;
    while (t--){
        int W, H; cin >> W >> H;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        rect table = rect(x1, y1, x2, y2);
        int w, h; cin >> w >> h;
        int border_l = w;
        int border_r = W - w;
        int border_b = h;
        int border_t = H - h;
        int move_l = max(0, border_l - table.x1);
        int move_r = max(0, table.x2 - border_r);
        int move_b = max(0, border_b - table.y1);
        int move_t = max(0, table.y2 - border_t);
        if (table.w() + w > W){
            move_l = move_r = INF;
        }
        if (table.h() + h > H){
            move_b = move_t = INF;
        }
        int ans = min({move_l, move_r, move_b, move_t});
        if (ans == INF){
            cout << -1 << endl;
        } else {
            cout << fixed << setprecision(9) << (double)ans << endl;
        }
    }
    return 0;
}