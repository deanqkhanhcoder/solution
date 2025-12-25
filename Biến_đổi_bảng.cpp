#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("BOARD.INP", "r", stdin);
    freopen("BOARD.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            char c; cin >> c;
            a[i][j] = (c == 'B' ? 1 : 0);
        }
    }
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            char c; cin >> c;
            b[i][j] = (c == 'B' ? 1 : 0);
        }
    }
    vector<vector<int>> diff(m, vector<int>(n));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            diff[i][j] = (a[i][j] == b[i][j] ? 0 : 1);
        }
    }
    vector<pair<int,int>> ans;
    ans.reserve((n * m + 1) / 2);
    for (int i = 0; i < m - 1; ++i){
        for (int j = 0; j < n - 1; ++j){
            if (diff[i][j] == 1){
                ans.push_back({i + 1, j + 1});
                diff[i][j] = 0;
                diff[i + 1][j] = 1 - diff[i + 1][j];
                diff[i][j + 1] = 1 - diff[i][j + 1];
                diff[i + 1][j + 1] = 1 - diff[i + 1][j + 1];
            }
        }
    }
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (diff[i][j] == 1){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (pair<int,int> &p : ans){
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}