#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int MAXC = (int)1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> c(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i] >> c[i];
    }
    vector<ll> temp = c;
    sort(temp.begin(), temp.end());
    for (ll &x : c){
        x = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
    }
    vector<vector<int>> pos(MAXC + 1, vector<int>());
    for (int i = 0; i < n; ++i){
        pos[c[i]].push_back(a[i]);
    }
    vector<vector<ll>> pref(MAXC + 1, vector<ll>());
    for (int c = 1; c <= MAXC; c++){
        if (pos[c].empty()) continue;
        int m = (int)pos[c].size();
        pref[c].assign(m + 1, 0);
        for (int i = 1; i <= m; ++i){
            pref[c][i] = pref[c][i - 1] + pos[c][i - 1];
        }
    }
    auto query = [&](ll col){
        return lower_bound(temp.begin(), temp.end(), col) - temp.begin() + 1;
    };
    ll global = 0;
    vector<ll> pen(MAXC + 1, 0);
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if (type == 1){
            int col; cin >> col;
            int x; cin >> x;
            global += x;
            pen[query(col)] += x;
        } else {
            int col; cin >> col;
            ll y; cin >> y;
            int idx = query(col);
            ll offset = global - pen[idx];
            int l = 0, r = (int)pos[idx].size();
            while (l < r){
                int mid = l + (r - l + 1) / 2;
                ll curr = pref[idx][mid] + 1LL * offset * mid;
                if (curr <= y) l = mid;
                else r = mid - 1;
            }
            cout << l << '\n';
        }
    }
    // for (int i = 0; i <= pos[2].size(); ++i){
    //     cout << pref[2][i] << ' ';
    // }
    return 0;
}