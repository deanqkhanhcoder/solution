#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> path;

void cycle_search(int node, int parent) {
    path.push_back(node);

    if (visited[node]) {
        auto it = find(path.begin(), path.end(), node);
        cout << path.end() - it << "\n";

        auto cycle = vector<int>(it, path.end());
        for (auto node : cycle) {
            cout << node << " ";
        }
        cout << "\n";

        exit(0);
    }

    visited[node] = true;

    for (auto next_node : graph[node]) {
        if (next_node != parent) {
            cycle_search(next_node, node);
        }
    }

    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cycle_search(i, 0);
        }
    }

    cout << "IMPOSSIBLE\n";
}