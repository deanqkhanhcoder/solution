#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> color;
vector<vector<int>> pos;
bool bfs(int i){
    color[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int &v : pos[u]){
            if (color[v] == 0){
                color[v] = (color[u] == 1 ? 2 : 1);
                q.push(v);
            } else if (color[u] == color[v]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    pos.assign(n + 1, {});
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        pos[a].push_back(b);
        pos[b].push_back(a);
    }
    color.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        if (color[i] == 0 && !bfs(i)){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << color[i] << " ";
    }
    return 0;
}