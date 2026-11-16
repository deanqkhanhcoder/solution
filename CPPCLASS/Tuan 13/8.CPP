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
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    vector<bool> is_bridge(m, false);
    int timer = 0;
    auto dfs = [&](auto && self, int u, int parentID) -> void {
        tin[u] = low[u] = ++timer;
        for (auto [v, id] : adj[u]){
            if (id == parentID) continue;
            if (tin[v]){
                low[u] = min(low[u], tin[v]);
            } else {
                self(self, v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]){
                    is_bridge[id] = true;
                }
            }
        }
    };
    for (int i = 1; i <= n; ++i){
        if (!tin[i]){
            dfs(dfs, i, -1);
        }
    }
    vector<vector<int>> adjBridge(n + 1);
    for (int i = 0; i < m; ++i){
        if (is_bridge[i]){
            auto [u, v] = edges[i];
            adjBridge[u].push_back(v);
            adjBridge[v].push_back(u);
        }
    }
    vector<bool> visited(n + 1, false);
    auto dfsCnt = [&](auto &&self, int u) -> ll {
        visited[u] = true;
        ll sz = 1;
        for (int v : adjBridge[u]){
            if (!visited[v]){
                sz += self(self, v);
            }
        }
        return sz;
    };
    ll ans = 0;
    for (int i = 1; i <= n; ++i){   
        if (!visited[i]){
            ll k = dfsCnt(dfsCnt, i);
            if (k >= 3){
                ll cnt = 1LL * (k - 1) * (k - 2) / 2;
                ans += cnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}