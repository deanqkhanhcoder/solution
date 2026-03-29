#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define gcd(a, b) __gcd(a, b)
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    int len = -1, l = -1, r = -1;
    vector<pair<int, int>> cur, pre;
    for (int i = 0; i < n; ++i){
        cur.clear();
        cur.push_back({a[i], i});
        for (auto &p : pre){
            int ngcd = gcd(a[i], p.first);
            if (ngcd == cur.back().first) continue;
            else cur.push_back({ngcd, p.second});
        }
        if (cur.back().first == 1){
            // cerr << "cur.back().first == 1: " << cur.back().second + 1 << ' ' << i + 1 << endl
            if (len == -1 || i - cur.back().second + 1 < len){
                len = i - cur.back().second + 1;
                l = cur.back().second + 1;
                r = i + 1;
            }
        }
        pre = cur;
    }
    if (len == -1){
        cout << -1;
    } else {
        cout << len << ' ' << l << ' ' << r;
    }
    return 0;
}