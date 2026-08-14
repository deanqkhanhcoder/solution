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
constexpr int MOD = (int)1e9 + 7;
struct entry {
    int rem;
    int val;
    int idx;
    bool operator<(const entry& o) const{
        if (rem != o.rem) return rem < o.rem;
        return val < o.val;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m), b(k);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    vector<int> S;              
    S.reserve(m + k + 2);
    S.push_back(0);
    S.push_back(n);
    for (int x : a) S.push_back(x);
    for (int x : b) S.push_back(x);
    sort(all(S));
    // S.erase(unique(all(S)), S.end());
    int sz = (int)S.size();
    vector<int> type(sz, 0);
    for (int x : a) {
        int idx = lower_bound(all(S), x) - S.begin();
        type[idx] = 1;
    }
    for (int x : b) {
        int idx = lower_bound(all(S), x) - S.begin();
        type[idx] = 2;
    }
    const int LIMIT = 29;
    vector<vector<entry>> S_rem(LIMIT + 1);
    for (int p = 0; p <= LIMIT; ++p){
        int step = (1 << p);
        S_rem[p].resize(sz);
        for (int i = 0; i < sz; ++i){
            S_rem[p][i] = {S[i] % step, S[i], i};
        }
        sort(all(S_rem[p]));
    }
    vector<vector<int>> dist(sz, vector<int>(LIMIT + 1, INF));
    dist[0][0] = 0;
    for (int i = 0; i < sz; ++i){
        int u_val = S[i];
        for (int p = 0; p <= LIMIT; ++p){
            if (dist[i][p] == INF) continue;
            int step = (1 << p);
            int rem = u_val % step;
            entry target = {rem, u_val, 0};
            auto it = upper_bound(all(S_rem[p]), target);
            if (it == S_rem[p].end() || it->rem != rem) continue;
            int next_idx = it->idx;
            int k = (it->val - u_val) >> p;
            int t = type[next_idx];
            int d = dist[i][p] + k; 
            if (t == 2){
                dist[next_idx][0] = min(dist[next_idx][0], d);
            } else if (t == 1){
                dist[next_idx][p] = min(dist[next_idx][p], d);
                if (p + 1 <= LIMIT) dist[next_idx][p + 1] = min(dist[next_idx][p + 1], d);
            } else {
                dist[next_idx][p] = min(dist[next_idx][p], d);
            }
        }
    }
    int ans = INF;
    for (int p = 0; p <= LIMIT; ++p){
        ans = min(dist[sz - 1][p], ans);
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}