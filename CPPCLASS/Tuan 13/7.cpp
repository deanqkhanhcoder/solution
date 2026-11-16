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
        adj[v].push_back(u);
    }
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    vector<int> cc(n + 1);
    int timer = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        tin[u] = low[u] = ++timer;
        int child = 0;
        int cnt = 0;
        for (int v : adj[u]){
            if (v == p) continue;
            if (tin[v]){
                low[u] = min(low[u], tin[v]);
            } else {
                self(self, v, u);
                child++;
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]){
                    cnt++;
                }
            }
        }
        if (p == -1){
            cc[u] = child;
        } else {
            cc[u] = cnt + 1;
        }
    };
    int components = 0;
    for (int i = 1; i <= n; ++i){
        if (!tin[i]){
            components++;
            dfs(dfs, i, -1);
        }
    }
    int ans = 0, maxVal = 0; 
    for (int i = 1; i <= n; ++i){
        int cnt = components - 1 + cc[i];
        if (cnt > maxVal){
            ans = i;
            maxVal = cnt;
        }
    }
    cout << maxVal << ' ' << ans << endl;
    return 0;
}