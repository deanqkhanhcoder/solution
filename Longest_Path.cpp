#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> topo;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v);
    }
    topo.push_back(u);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
        if (!visited[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
    vector<int> dp(n + 1, 0);
    int ans = 0;
    for(int u : topo){
        for(int v : adj[u]){
            dp[v] = max(dp[v], dp[u] + 1);
            ans = max(ans, dp[v]);
        }
    }
    cout << ans;
    return 0;
}