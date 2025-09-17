#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    string ans;
    vector<pair<int,int>> q;
    q.reserve(n);
    q.push_back({0,0});
    vector<vector<int>> visited(n, vector<int>(n, 0));
    for (int i = 0; i < 2*n - 1; ++i){
        char bst = 'Z' + 1;
        for (pair<int,int> p: q){
            bst = min(bst, grid[p.first][p.second]);
        }
        ans.push_back(bst);
        vector<pair<int,int>> nextq;
        nextq.reserve(n);
        for (auto [x, y]: q){
            if (grid[x][y] != bst) continue;
            if (x + 1 < n && visited[x + 1][y] != 1){
                visited[x+1][y] = 1;
                nextq.push_back({x + 1, y});
            }
            if (y + 1 < n && visited[x][y + 1] != 1){
                visited[x][y + 1] = 1;
                nextq.push_back({x, y + 1});
            }
        }
        q = nextq;
    }
    cout << ans;
    return 0;
}