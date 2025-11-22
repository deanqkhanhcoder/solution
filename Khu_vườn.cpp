#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    auto check = [&](int x, int y){
        return (0 <= x && x < n && 0 <= y && y < m);
    };
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    auto bfs = [&](int i, int j){
        int cnt = (a[i][j] == 'x') ? 1 : 0;        
        queue<pair<int,int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int d = 0; d < 4; ++d){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (check(nx, ny) && !visited[nx][ny] && a[nx][ny] != '#'){
                    visited[nx][ny] = true;
                    if (a[nx][ny] == 'x') cnt++;
                    q.push({nx, ny});
                }
            }
        }
        return cnt;
    };
    vector<int> res;
    res.reserve(n * m / 2);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (a[i][j] != '#' && !visited[i][j]){
                int cnt = bfs(i, j);
                if (cnt == 0) continue;
                else res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());
    ostringstream oss;
    for (int i = 0; i < (int)res.size(); ++i) {
        oss << res[i] << ' ';
    }
    string s = oss.str();
    cout << s;
    return 0;
}