#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start;
    vector<pair<int, int>> mos;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'M') mos.push_back({i, j});
        }
    }
    auto [sx, sy] = start;
    if (sx == 0 || sx == n - 1 || sy == 0 || sy == m - 1){
        cout << "YES\n0\n";
        return 0;
    }
    vector<vector<int>> distm(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> qm;
    for (auto [x, y]: mos){
        distm[x][y] = 0;
        qm.push({x, y});
    }
    tuple<int,int,char> dirs[4] = {
        {1, 0, 'D'},
        {-1, 0, 'U'},
        {0, -1, 'L'},
        {0, 1, 'R'}
    };
    while (!qm.empty()){
        auto [x, y] = qm.front(); qm.pop();
        for (auto [dx, dy, c] : dirs){
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (distm[nx][ny] != INT_MAX) continue;
            distm[nx][ny] = distm[x][y] + 1;
            qm.push({nx, ny});
        }
    }
    vector<vector<int>> dista(n, vector<int>(m, INT_MAX));
    vector<vector<tuple<int,int,char>>> parent(n, vector<tuple<int,int,char>>(m));
    queue<pair<int,int>> q;
    dista[sx][sy] = 0;
    q.push({sx, sy});
    pair<int, int> exit = {-1, -1};
    bool ok = false;
    while (!q.empty() && !ok){
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy, c] : dirs){
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (dista[nx][ny] != INT_MAX) continue;
            int move = dista[x][y] + 1;
            if (move >= distm[nx][ny]) continue;
            dista[nx][ny] = move;
            parent[nx][ny] = {x, y, c}; 
            q.push({nx, ny});
            if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1){
                ok = true;
                exit = {nx, ny};
                break;
            }
        }
    }
    if (exit == make_pair(-1, -1)) {
        cout << "NO";
        return 0;
    }
    string path;
    auto [x, y] = exit;
    while (x != sx || y != sy) {
        auto [px, py, c] = parent[x][y];
        path.push_back(c);
        x = px; y = py;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path;
    return 0;
}