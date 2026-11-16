#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;
constexpr int MAXN = 200005;
constexpr int LOG = 19;
vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int diff[MAXN];
int unvisited = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto build = [&](auto &&self, int u, int p) -> void {
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i){
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]){
            if (v == p) continue;
            depth[v] = 1 + depth[u];
            self(self, v, u);
        }
    };
    auto getLCA = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) swap(u, v);
        int k = depth[u] - depth[v];
        for (int i = LOG - 1; i >= 0; --i){
            if ((k >> i) & 1){
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i){
            if (up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };
    build(build, 1, 1);
    int m; cin >> m;
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        int c = getLCA(a, b);
        diff[a]++;
        diff[b]++;
        diff[c] -= 2;
    }
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (int v : adj[u]){
            if (v == p) continue;
            self(self, v, u);
            diff[u] += diff[v];
        }
        if (u != 1 && diff[u] == 0){
            unvisited++;
        }
    };
    dfs(dfs, 1, 1);
    cout << unvisited << endl;
    return 0;
}
