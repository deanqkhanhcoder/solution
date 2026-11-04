#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    int n, k; cin >> n >> k;
    vector<int> exit(k);
    vector<int> dist(n + 1, -1);
    queue<int> q;
    for (int &x : exit){
        cin >> x;
        dist[x] = 0;
        q.push(x);
    }
    int m; cin >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; ++i) cout << dist[i] << ' ';
    cout << endl;
    // code here    
    return 0;
}