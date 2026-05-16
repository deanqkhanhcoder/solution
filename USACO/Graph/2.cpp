#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        adj[v].push_back(u);
    }
    vector<int> color(n);
    for (int b = 0; b < n; ++b){
        vector<bool> visited(5, false);
        for (int a : adj[b]) {
            visited[color[a]] = true;
        }
        for (int c = 1; c <= 4; ++c){
            if (!visited[c]){
                color[b] = c;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i){
        cout << color[i];
    }
    return 0;
}