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
    string s; cin >> s;
    int n = s.length();
    auto getTag = [](char c) -> int {
        if (c == 'E') return 0;
        else if (c == 'N') return 1;
        else if (c == 'S') return 2;
        else if (c == 'W') return 3;
        return -1;
    };
    int x = 0, y = 0;
    vector<pair<int, int>> a;
    a.reserve(n + 1);
    a.push_back({x, y});
    for (int i = 0; i < n; ++i){
        int tag = getTag(s[i]);
        if (tag == 0) y++;
        else if (tag == 1) x++; 
        else if (tag == 2) x--; 
        else if (tag == 3) y--;
        a.push_back({x, y}); 
    }
    vector<pair<int,int>> temp = a;
    sort(all(temp));
    temp.erase(unique(all(temp)), temp.end());
    int m = sz(temp);
    auto getId = [&](pair<int, int> p){
        return lower_bound(all(temp), p) - temp.begin();
    };
    vector<vector<pair<int, int>>> adj(m);
    for (int i = 0; i < n; ++i){
        int u = getId(a[i]);
        int v = getId(a[i + 1]);
        int fwd = getTag(s[i]);
        int bwd = 3 - fwd;
        adj[u].push_back({v, fwd});
        adj[v].push_back({u, bwd});
    }
    for (int i = 0; i < m; ++i){
        sort(all(adj[i]));
        adj[i].erase(unique(all(adj[i])), adj[i].end());
    }
    int start = getId({0, 0});
    int end = getId(a.back());
    vector<int> dist(m, INF);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto [v, dir] : adj[u]){
            if (dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    char DIR[4] = {'E', 'N', 'S', 'W'};
    string res = "";
    int curr = end;
    while(curr != start){
        for (int i = 0; i < 4; ++i){
            for (auto [v, dir] : adj[curr]){
                if (i == dir && dist[v] == dist[curr] - 1){
                    res += DIR[i];
                    curr = v;
                    goto found;
                }
            }
        }
        found:;
    }
    cout << res << endl;
    return 0;
}