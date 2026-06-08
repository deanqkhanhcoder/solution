#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> grid[i][j];
        }
    }
    vector<int> col(2, 0);
    int ans_col = 0;
    for (int j = 0; j < n; ++j){
        fill(all(col), 0);
        for (int i = 0; i < n; ++i){
            col[i % 2] += grid[i][j];
        }
        ans_col += max(col[0], col[1]);
    }
    vector<int> row(2, 0);
    int ans_row = 0;
    for (int i = 0; i < n; ++i){
        fill(all(row), 0);
        for (int j = 0; j < n; ++j){
            row[j % 2] += grid[i][j];
        }
        ans_row += max(row[0], row[1]);
    }
    cout << max(ans_col, ans_row);
    return 0;
}