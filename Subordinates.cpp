#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> subordinates;

int dfs(int node) {
    int count = 0;
    for (int child : tree[node]) {
        count += 1 + dfs(child);
    }
    subordinates[node] = count;
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    tree.assign(n + 1, vector<int>());
    subordinates.assign(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    return 0;
}
