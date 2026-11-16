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
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    vector<bool> inStack(n + 1);
    vector<int> st;
    vector<vector<int>> scc;
    int timer = 0;
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
            vector<int> c;
            while(true){
                int v = st.back();
                st.pop_back();
                inStack[v] = false;
                c.push_back(v);
                if (v == u) break;
            }
            scc.push_back(c);
        }
    };
    for (int i = 1; i <= n; ++i){
        if (!tin[i]){
            dfs(dfs, i);
        }
    }
    int ans = sz(scc);
    cout << ans << endl;
    for (vector<int> &c : scc){
        // sort(all(c));
        for (int u : c) {
            cout << u << ' ';
        }
        cout << endl;
    }
    return 0;
}