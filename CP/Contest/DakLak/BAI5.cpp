#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = 1e9;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int M, N;
int H[105][105];
int Dist[105][105];
bool inQueue[105][105];

int calc(int h1, int h2) {
    if (h1 == h2) return 1;
    return 1 + abs(h1 - h2) * 2; 
}

void solve() {
    cin >> M >> N;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> H[i][j];
            Dist[i][j] = INF;
            inQueue[i][j] = false;
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    Dist[x1][y1] = 0;
    inQueue[x1][y1] = true;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;
        inQueue[r][c] = false;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 1 && nr <= M && nc >= 1 && nc <= N) {
                int cost = calc(H[r][c], H[nr][nc]);
                if (Dist[r][c] + cost < Dist[nr][nc]) {
                    Dist[nr][nc] = Dist[r][c] + cost;
                    if (!inQueue[nr][nc]) {
                        q.push({nr, nc});
                        inQueue[nr][nc] = true;
                    }
                }
            }
        }
    }
    if (Dist[x2][y2] == INF) cout << 0;
    else cout << Dist[x2][y2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("BAI5.INP", "r", stdin);
    freopen("BAI5.OUT", "w", stdout);
    solve();
    return 0;
}