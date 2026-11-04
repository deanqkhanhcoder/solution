#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <array>
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
    int m, n, cS, cT; cin >> m >> n >> cS >> cT;
    cS--; cT--;
    vector<string> a(m);
    int xS, yS, xT, yT;
    for (int i = 0; i < m; ++i){
        string s; cin >> s;
        for (int j = 0; j < n; ++j){
            if (s[j] == 'S'){
                xS = i;
                yS = j;
            } else if (s[j] == 'T'){
                xT = i;
                yT = j;
            }
        }
        a[i] = s;
    }
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0 ,-1};
    int dist[50][50][4][5];
    memset(dist, -1, sizeof(dist));
    queue<array<int,4>> q;
    dist[xS][yS][0][cS] = 0;
    q.push({xS, yS, 0, cS});
    while(!q.empty()){
        auto [x, y, dir, color] = q.front();
        q.pop();
        int nd = (dir + 1) % 4;
        if (dist[x][y][nd][color] == -1){
            dist[x][y][nd][color] = dist[x][y][dir][color] + 1;
            q.push({x, y, nd, color});
        }
        nd = (dir + 3) % 4;
        if (dist[x][y][nd][color] == -1){
            dist[x][y][nd][color] = dist[x][y][dir][color] + 1;
            q.push({x, y, nd, color});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] != '#'){
            int ncolor = (color + 4) % 5;
            if (dist[nx][ny][dir][ncolor] == -1){
                dist[nx][ny][dir][ncolor] = dist[x][y][dir][color] + 1;
                q.push({nx, ny, dir, ncolor});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 4; ++i){
        if (dist[xT][yT][i][cT] != -1){
            ans = min(ans, dist[xT][yT][i][cT]);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}