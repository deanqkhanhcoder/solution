#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<vector<int>> grid;
pair<int, int> dxy[4] = {{1, 0}, {0 , 1}, {-1 , 0}, {0, -1}};
bool ok(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}
bool check(int mid){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(n, false));
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i){
            int nx = x + dxy[i].first;
            int ny = y + dxy[i].second;
            // cerr << "nx : " << nx << " ny : " << ny << endl;
            if (ok(nx, ny) && !visited[nx][ny] && abs(grid[nx][ny] - grid[x][y]) <= mid){
                if (nx == n - 1 && ny == n - 1) return true;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    // vector<vector<int>> grid(n, vector<int>(n));
    grid.assign(n, vector<int>(n));
    int maxd = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> grid[i][j];
            if (i > 0) maxd = max(maxd, abs(grid[i][j] - grid[i - 1][j]));
            if (j > 0) maxd = max(maxd, abs(grid[i][j] - grid[i][j - 1]));
        }
    }
    int lo = 0;
    int hi = maxd;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if (check(mid)){
            hi = mid;
            // cerr << "ok" << endl;
        }
        else lo = mid + 1;
    }
    cout << lo;
    // if (check(1)){
    //     cerr << "ok";
    // }
    return 0;
    // for (int i = 0; i < n ;++i){
    //     for (int j = 0; j < n; ++j)
    // }
}   