#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
// #define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;
struct Node {
    int year, i, j;
    bool operator<(const Node& o) const{
        return year > o.year;
    }
};
struct DSU{
    vector<int> parent, sz;
    DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int u){
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    int unite(int u, int v){
        u = find(u);
        v = find(v);
        if (sz[u] < sz[v]) swap(u, v);
        if (u != v){
            parent[v] = u;
            sz[u] += sz[v];
            return true;
        }
        return false;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int m, n; cin >> m >> n;
    vector<Node> a;
    a.reserve(m * n); 
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            a.push_back({x, i, j});
        }
    }
    int T; cin >> T;
    vector<int> queries(T);
    for (int &x : queries) cin >> x;
    sort(all(a));
    DSU dsu(m * n);
    vector<vector<bool>> active(m + 1, ve tor<bool>(n + 1, false));
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {-1, 1, 0, 0};
    vector<int> ans(T);
    int res = 0;
    int idx = 0;
    for (int k = T - 1; k >= 0; --k){
        int curr = queries[k];
        while(idx < m * n && a[idx].year > curr){
            int i = a[idx].i;
            int j = a[idx].j;
            active[i][j] = true;
            res++;
            int u = (i - 1) * n + j;
            for (int d = 0; d < 4; ++d){
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni >= 1 && ni <= m && nj >= 1 && nj <= n && active[ni][nj]){
                    int v = (ni - 1) * n + nj;
                    if (dsu.unite(u, v)){
                        res--;
                    }
                }
            }
            idx++;
        }
        ans[k] = res;
    }
    for (int i = 0; i < T; ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}