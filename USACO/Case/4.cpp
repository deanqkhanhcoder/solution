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
    int n, m; cin >> n >> m;
    vector<vector<bool>> winning(n, vector<bool>(n));
    for (int i = 0; i < n; ++i){
        string status; cin >> status;
        for (int j = 0; j <= i; ++j){
            if (status[j] == 'W'){
                winning[i][j] = true;
                winning[j][i] = false;
            }
            if (status[j] == 'L'){
                winning[i][j] = false;
                winning[j][i] = true;
            }
        }
    }
    while (m--){
        int l, r; cin >> l >> r;
        l--;
        r--;
        int cnt = 0;
        for (int x = 0; x < n; ++x){
            if (winning[x][l] && winning[x][r]) cnt++;
        }
        ll ans = 1LL * cnt * n + 1LL * cnt * (n - cnt);
        cout << ans << endl;
    }
    return 0;
}