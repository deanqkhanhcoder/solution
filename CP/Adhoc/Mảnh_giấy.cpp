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
    int n, m, f, d, c; cin >> n >> m >> f >> d >> c;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    for (int q = 0; q < f; ++q){
        int i, j; cin >> i >> j;
        matrix[i][j] = 1;
    }
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            pref[i][j] = matrix[i][j] + pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
            // cerr << "pref[" << i << "][" << j << "] = " << pref[i][j] << endl;
        }
    }
    auto query = [&](int x1, int y1, int x2, int y2) -> int{
        return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
    };
    auto check = [&](int k){
        for (int i = k; i <= n; ++i){
            for (int j = k; j <= m; ++j){
                int sum = query(i - k + 1, j - k + 1, i, j);
                // cerr << i << " " << j << endl;
                if (sum <= c){
                    return sum <= c;
                }
            }
        }
        return false;
    };
    int lo = 0, hi = min(n, m) / d;
    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        int k = mid * d;
        // cerr << "k = " << k << " mid = " << mid << endl;
        if (check(k)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo * d;
    return 0;
}