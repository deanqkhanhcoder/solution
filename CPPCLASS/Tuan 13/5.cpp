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
    int m, s, t; cin >> m >> s >> t;
    vector<pair<int, int>> a(m);
    vector<int> temp;
    temp.reserve(2 * m + 2);
    temp.push_back(s);
    temp.push_back(t);
    for (auto &p : a) {
        cin >> p.first >> p.second;
        temp.push_back(p.first);
        temp.push_back(p.second);
    }
    sort(all(temp));
    temp.erase(unique(all(temp)), temp.end());
    int V = sz(temp);
    auto getId = [&](int node){
        return lower_bound(all(temp), node) - temp.begin();
    };
    auto check = [&](int n){
        vector<vector<int>> adj(V);
        for (int i = 0; i <= n; ++i){
            int u = getId(a[i].first);
            int v = getId(a[i].second);
            adj[u].push_back(v);
        }
        int start = getId(s);
        int end = getId(t);
        if (adj[start].empty()) return false;
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if (u == end) return true;
            for (int v : adj[u]){
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
        return false;
    };
    if (!check(m - 1)){
        cout << 0 << endl;
        return 0;
    }
    int l = 0, r = m - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l + 1 << endl;
    return 0;
}