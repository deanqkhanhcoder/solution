#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int n;
vector<vector<int>> adj;
vector<long long> dp0, dp1;
vector<int> parent;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent.assign(n + 1, 0);
    dp0.assign(n + 1, 1);
    dp1.assign(n + 1, 1);

    queue<int> q;
    q.push(1);
    parent[1] = -1;
    vector<int> lf;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        lf.push_back(v);
        for (int u : adj[v]) {
            if (u == parent[v]) continue;
            parent[u] = v;
            q.push(u);
        }
    }
    reverse(lf.begin(), lf.end());
    for (int v : lf) {
        int p = parent[v];
        if (p == -1) continue;
        dp0[p] = dp0[p] * ((dp0[v] + dp1[v]) % MOD) % MOD;
        dp1[p] = dp1[p] * dp0[v] % MOD;
    }
    cout << ((ll)dp0[1] + dp1[1]) % MOD;
    return 0;
}
