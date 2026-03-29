#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, S; cin >> n >> S;
    vector<pair<int, int>> gift0;
    vector<pair<int, int>> gift1;
    // vector<int> indexed;
    ll sw = 0, sv = 0;
    for (int i = 0; i < n; ++i){
        int w, v, c; cin >> w >> v >> c;
        if (c == 1){
            gift1.push_back({w, v});
            sw += w;
            sv += v;
        } else if (c == 0){
            gift0.push_back({w, v});
            // indexed.push_back(w);
        }
    }
    sort(gift0.begin(), gift0.end());
    int m = gift0.size();
    for (int i = 1; i < m; ++i){
        gift0[i].second = max(gift0[i].second, gift0[i - 1].second);
    }
    ll ans = sv;
    for (auto &p : gift1){
        ll limit = S - (sw - p.first);
        if (limit < 0) continue;
        int idx = upper_bound(gift0.begin(), gift0.end(), make_pair(limit, 0), [](auto &a, auto &b){
            return a.first < b.first;
        }) - gift0.begin();
        if (idx == 0) continue;
        idx--;
        ans = max(ans, sv - p.second + gift0[idx].second);
    }
    cout << ans;
    return 0;
}  