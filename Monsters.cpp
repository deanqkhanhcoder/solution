#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
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
        cout << "YES\n";
        cout << "";
        return 0;
    }
    vector<vector<int>> distm(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> q;
    for (auto [x, y]: mos){
        distm[x][y] = 0;
        q.push({x, y});
    }
    tuple<int,int,char> dirs[4] = {
        {1, 0, 'D'},
        {-1, 0, 'U'},
        {0, -1, 'L'},
        {0, 1, 'R'}
    };
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy, c] : dirs){
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (grid[nx][ny] != INT_MAX) continue;
            distm[nx][ny] = distm[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}