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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<pair<int ,int>> raw(n);
    for (auto &p : raw) cin >> p.first >> p.second;
    sort(all(raw));
    vector<pair<int, int>> time;
    pair<int, int> curr = raw[0];
    for (int i = 1; i < n; ++i){
        int l = raw[i].first, r = raw[i].second;
        if (l < curr.second){
            curr.second = max(curr.second, r);
        } else {
            time.push_back(curr);
            curr = {l, r};
        }
    }
    time.push_back(curr);
    while (m--){
        int k; cin >> k;
        auto it = upper_bound(all(time), k, [](int val, auto &p){
            return val < p.second;
        });
        if (it == time.end()){
            cout << -1 << endl;
            continue;
        }
        int idx = it - time.begin();
        if (k >= time[idx].first){
            cout << 0 << endl;
            continue;
        } else {
            cout << time[idx].first - k << endl;
            continue;
        }
    }
    return 0;
}