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
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    vector<ll> sz(n + 1);
    vector<ll> ans(n + 1);
    int timer = 0;
    auto dfs = [&](auto &&self, int u, int parent = -1) -> void {
        tin[u] = low[u] = ++timer;
        sz[u] = 1;
        ll sumSq = 0;
        ll sum = 0;
        for (int v : adj[u]){
            if (v == parent) continue;
            if (tin[v]){
                low[u] = min(low[u], tin[v]);
            } else {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
                sz[u] += sz[v];
                if (low[v] >= tin[u]){
                    sumSq += 1LL * sz[v] * sz[v];
                    sum += sz[v];
                }
            }
        }
        int rem = n - 1 - sum;
        sumSq += 1LL * rem * rem;
        ans[u] = 2 * (n - 1);
        ans[u] += 1LL * (n - 1) * (n - 1);
        ans[u] -= sumSq;
    };
    dfs(dfs, 1);
    for (int i = 1; i <= n; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}