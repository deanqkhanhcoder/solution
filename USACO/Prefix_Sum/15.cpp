#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     freopen("lazy.in", "r", stdin);
     freopen("lazy.out", "w", stdout);
    int n, k; cin >> n >> k;
    const int LEN = 2 * n;
    vector<vector<int>> rot(LEN + 1, vector<int>(LEN + 1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int val; cin >> val;
            int x = i + j;
            int y = i - j + n;
            rot[x][y] = val;
        }
    }
    vector<vector<ll>> pref(LEN + 1, vector<ll>(LEN + 1, 0));
    for (int i = 1; i <= LEN; ++i){
        for (int j = 1; j <= LEN; ++j){
            pref[i][j] = rot[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    auto get_area = [&](int x, int y){
        int l_x = max(1, x - k);
        int r_x = min(LEN, x + k);
        int l_y = max(1, y - k);
        int r_y = min(LEN, y + k);
        return pref[r_x][r_y] - pref[l_x - 1][r_y] - pref[r_x][l_y - 1] + pref[l_x - 1][l_y - 1];
    };
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x = i + j;
            int y = i - j + n;
            ans = max(ans, get_area(x, y));
        }
    }
    cout << ans;
    return 0;
}