#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dir[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<vector<int>> a(n+2, vector<int>(m+2, -1));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    auto check = [&](int xx, int yy) {
        for (int d = 0; d < 8; ++d) {
            int nx = xx + dir[d][0];
            int ny = yy + dir[d][1];
            if (a[nx][ny] >= a[xx][yy]) return false;
        }
        return true;
    };

    for (int x = 1; x <= n; ++x){
        for (int y = 1; y <= m; ++y){
            if (check(x, y)) cnt++;
        }
    }

    cout << cnt;
    return 0;
}
