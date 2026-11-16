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
    // code here    
    int n, m, s; cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
        sort(all(adj[i]));
        adj[i].erase(unique(all(adj[i])), adj[i].end());
    }
    if (adj[s].empty()){
        cout << 0 << endl;
        return 0;
    }
    vector<int> dist(n + 1, -1);
    vector<int> cnt(n + 1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    cnt[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (dist[v] == -1){
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1){
                cnt[v] = min(2, cnt[v] + cnt[u]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (i != s && cnt[i] >= 2){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}