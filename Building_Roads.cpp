#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
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
    vector<bool> visited(n + 1, false);
    vector<int> ans;
    for (int i = 1; i <= n; ++i){
        if (!visited[i]) {
            ans.push_back(i);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int &v : pos[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    int k = ans.size() - 1;
    cout << k << "\n";
    for (int i = 1; i <= k; i++) {
        cout << ans[i - 1] << " " << ans[i] << "\n";
    }
    return 0;
}