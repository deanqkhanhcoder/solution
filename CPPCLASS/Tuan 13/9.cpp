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
    int n, m, K, L; cin >> n >> m >> K >> L;
    // vector<pair<int, int>> edges;
    vector<bool> isA(n + 1, false);
    vector<bool> isB(n + 1, false);
    for (int i = 0; i < K; ++i){
        int u; cin >> u;
        isA[u] = true;
    }
    for (int i = 0; i < L; ++i){
        int u; cin >> u;
        isB[u] = true;
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    vector<int> sumA(n + 1);
    vector<int> sumB(n + 1);
    int timer = 0;
    int ans = 0;
    auto dfs = [&](auto &&self, int u, int parentID) -> void {
        tin[u] = low[u] = ++timer;
        sumA[u] = isA[u];
        sumB[u] = isB[u];
        for (auto [v, id] : adj[u]){
            if (id == parentID) continue;
            if (tin[v]){
                low[u] = min(low[u], tin[v]);
            } else {
                self(self, v, id);
                low[u] = min(low[u], low[v]);
                sumA[u] += sumA[v];
                sumB[u] += sumB[v];
                if (low[v] > tin[u]){
                    if (sumA[v] == 0 || sumA[v] == K || sumB[v] == 0 || sumB[v] == L){
                        ans++;
                    }
                }
            }
        }
    };
    dfs(dfs, 1, -1);
    cout << ans << endl;
    return 0;
}