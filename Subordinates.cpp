#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> g;
vector<int> ans;
int n;
int dfs(int u) {
    for (int v : g[u]) {
        ans[u] += 1;
        dfs(v);
    }
    return ans[u];
}
int main() {
    cin >> n;
    g.assign(n+1, {});
    ans.assign(n+1, 0);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
