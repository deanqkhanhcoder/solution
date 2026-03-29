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
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int,int> apos;
    pair<int,int> bpos;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> grid[i][j];
            if (grid[i][j] == 'A') apos = {i, j};
            if (grid[i][j] == 'B') bpos = {i, j};
        }
    }
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> pt(n, vector<pair<int, int>>(m));
    vector<vector<char>> move(n, vector<char>(m));
    q.push(apos);
    visited[apos.first][apos.second] = true;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char dmove[4] = {'D', 'U', 'R', 'L'};
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                pt[nx][ny] = {x, y};
                move[nx][ny] = dmove[k];
                q.push({nx, ny});
            }
        }
    }
    auto [x, y] = bpos;
    if (!visited[x][y]) {
        cout << "NO";
        return 0;
    }
    string path = "";
    while (bpos != apos) {
        auto [x, y] = bpos;
        path.push_back(move[x][y]);
        bpos = pt[x][y];
    }
    reverse(path.begin(), path.end());
    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path;
    return 0;
}