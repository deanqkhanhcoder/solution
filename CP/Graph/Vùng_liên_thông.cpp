#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj;
vector<char> visited;
void bfs(int i) {
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, 0);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (!visited[i]){
            bfs(i);
            ++ans;
        }
    }
    cout << ans;
    return 0;
}