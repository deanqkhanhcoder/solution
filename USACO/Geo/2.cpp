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
    static rect maxest(const rect &a, const rect &b){
        int x1 = min(a.x1, b.x1);
        int y1 = min(a.y1, b.y1);
        int x2 = max(a.x2, b.x2);
        int y2 = max(a.y2, b.y2);
        rect ans = rect(x1, y1, x2, y2);
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    // code here
    int x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    rect fi = rect(x1, y1, x2, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    rect se = rect(x1, y1, x2, y2);
    rect ans = rect::maxest(fi, se);
    int res = max(ans.x2 - ans.x1, ans.y2 - ans.y1);
    cout << res * res;
    return 0;
}