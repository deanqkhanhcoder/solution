#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    for (int s = 1; s <= n; ++s) {
        if (visited[s]) continue;
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                } else if (v != parent[u]) {
                    vector<int> cu, cv;
                    int x = u, y = v;
                    while (x != -1) {cu.push_back(x); x = parent[x];}
                    while (y != -1) {cv.push_back(y); y = parent[y];}
                    reverse(cu.begin(), cu.end());
                    reverse(cv.begin(), cv.end());
                    int lu = cu.size(), lv = cv.size();
                    int i = 0, lca = -1;
                    for (; i < min(lu, lv) && cu[i] == cv[i]; ++i) lca = cu[i];
                    vector<int> c;
                    for (int j = lu - 1; cu[j] != lca; --j) c.push_back(cu[j]);
                    c.push_back(lca);
                    for (int j = i; j < lv; ++j) c.push_back(cv[j]);
                    c.push_back(u);
                    cout << c.size() << "\n";
                    for (int node : c) cout << node << " ";
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
