#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <array>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> pref(n + 1, vector<int>(m + 1 , 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char c; cin >> c;
            int bit = (c == '.');
            pref[i][j] = bit + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    auto get = [&](int U, int L, int D, int R){
        int ans = pref[D][R] - pref[D][L - 1] - pref[U - 1][R] + pref[U - 1][L - 1];
        return ans;
    };
    vector<vector<array<int, 11>>> cnt(n + 1, vector<array<int, 11>>(m + 1, array<int, 11>{}));
    for (int k = 1; k <= 10; ++k){
        for (int i = k; i <= n; ++i){
            for (int j = k; j <= m; ++j){
                int total = get(i - k + 1, j - k + 1, i , j);
                int bit = (total == k * k);
                cnt[i][j][k] = bit + cnt[i - 1][j][k] + cnt[i][j - 1][k] - cnt[i - 1][j - 1][k];
            }
        }
    }
    auto query = [&](int U, int L, int D, int R, int K){
        int u = U + K - 1;
        int l = L + K - 1;
        if (u > D || l > R) return 0;
        int ans = cnt[D][R][K] - cnt[D][l - 1][K] - cnt[u - 1][R][K] + cnt[u - 1][l - 1][K];
        return ans;
    };
    while(q--){
        int U, L, D, R, K; cin >> U >> L >> D >> R >> K;
        cout << query(U, L, D, R, K) << endl;
    }
    return 0;
}