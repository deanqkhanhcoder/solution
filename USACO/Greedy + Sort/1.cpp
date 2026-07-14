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
struct element {
    int cost; bool is_usb;
    bool operator<(const element &o) const{
        return cost < o.cost;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    int a, b, c; cin >> a >> b >> c;
    int n; cin >> n;
    vector<element> item(n);
    for (int i = 0; i < n; ++i){
        int x; string s;
        cin >> x >> s;
        item[i].cost = x;
        item[i].is_usb = (s == "USB");
    }
    sort(all(item));
    int collect = 0;
    ll cost = 0;
    for (int i = 0; i < n && (a != 0 || b != 0 || c != 0); ++i){
        if (item[i].is_usb){
            if (a == 0){
                if (c == 0) continue;
                c--;
            } else {
                a--;
            }
            collect++;
            cost += item[i].cost;
        } else {
            if (b == 0){
                if (c == 0) continue;
                c--;
            } else {
                b--;
            }
            collect++;
            cost += item[i].cost;
        }
    }
    cout << collect << ' ' << cost << endl;
    return 0;
}