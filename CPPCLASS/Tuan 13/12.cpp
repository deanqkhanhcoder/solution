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
    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(v); 
    }
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    vector<bool> inStack(n + 1);
    vector<int> sz(n + 1);
    vector<int> id(n + 1);
    vector<int> st;
    int timer = 0;
    int scc = 0;
    auto dfs = [&](auto &&self, int u) -> void {
        tin[u] = low[u] = ++timer;
        st.push_back(u);
        inStack[u] = true;
        for (int v : adj[u]){
            if (!tin[v]){
                self(self, v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]){
                low[u] = min(low[u], tin[v]);
            }
        }
        if (low[u] == tin[u]){
            scc++;
            while(true){
                int v = st.back();
                st.pop_back();
                inStack[v] = false;
                id[v] = scc;
                sz[scc]++;
                if (v == u) break;
            }
        }
    };
    for (int i = 1; i <= n; ++i){
        if (!tin[i]){
            dfs(dfs, i);
        }
    }
    vector<int> cnt(n + 1);
    for (auto [u, v] : edges){
        if (id[u] == id[v]){
            int currScc = id[u];
            cnt[currScc]++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= scc; ++i){
        ans += 1LL * sz[i] * (sz[i] - 1) - cnt[i];
    }
    cout << ans << endl;
    return 0;
}