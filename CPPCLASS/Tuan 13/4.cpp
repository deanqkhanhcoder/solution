#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    int dist[50][50][4];
    memset(dist, -1, sizeof(dist));
    int dx[5] = {0, 0, -1, 1, 0};
    int dy[5] = {-1, 1, 0, 0, 0};
    pair<int, int> start = {m - 1, 0};
    pair<int, int> end = {0, n - 1};
    queue<tuple<int, int, int>> q;
    dist[start.first][start.second][0] = 0;
    q.push({start.first, start.second, 0});
    while(!q.empty()){
        auto [x, y, t] = q.front();
        q.pop();
        if (x == end.first && y == end.second){
            cout << t << endl;
            return 0;
        }
        int next_t = t + 1;
        int next_rem = next_t % 4;
        for (int i = 0; i < 5; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                int status = (a[nx][ny] - next_rem + 4) % 4;
                if (status != 0 && dist[nx][ny][next_rem] == -1){
                    dist[nx][ny][next_rem] = next_t;
                    q.push({nx, ny, next_t});
                }
            }
        }
    }
    return 0;
}