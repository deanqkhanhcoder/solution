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
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        pos[a].push_back(b);
        pos[b].push_back(a);
    }
    vector<int> ans(n + 1, -1);
    ans[1] = 0;
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int &v : pos[u]) {
            if (ans[v] == -1){
                ans[v] = ans[u] + 1;
                parent[v] = u;
                q.push(v);
            }
            }
        }
    if (ans[n] == -1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans[n] + 1 << "\n";
    vector<int> res;
    for (int cur = n; cur != -1; cur = parent[cur])
        res.push_back(cur);
    reverse(res.begin(), res.end());
    for (int i = 0; i < (int)res.size(); i++){
        cout << res[i] << ' ';
    }
    return 0;
}