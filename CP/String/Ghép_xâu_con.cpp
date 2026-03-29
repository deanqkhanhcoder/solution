#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <cstring>
using namespace std;
constexpr int MOD = (int)1e9 + 7;

void add(int &a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    string a; cin >> a;
    string b; cin >> b;
    int dp0[m + 1][k + 1], dp1[m + 1][k + 1];
    int ne0[m + 1][k + 1], ne1[m + 1][k + 1];
    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));
    dp0[0][0] = 1;
    for (int i = 0; i < n; ++i){
        char c = a[i];
        memset(ne0, 0, sizeof(ne0));
        memset(ne1, 0, sizeof(ne1));
        for (int j = 0; j <= m; ++j){
            for (int t = 0; t <= k; ++t){
                int v0 = dp0[j][t];
                int v1 = dp1[j][t];
                if (!v0 && !v1) continue;
                if (v0){
                    add(ne0[j][t], v0);
                    if (j < m && t < k && c == b[j])
                        add(ne1[j + 1][t + 1], v0);
                }
                if (v1){
                    if (j < m && c == b[j])
                        add(ne1[j + 1][t], v1);
                    add(ne0[j][t], v1);
                    if (j < m && t < k && c == b[j])
                        add(ne1[j + 1][t + 1], v1);
                }
            }
        }
        memcpy(dp0, ne0, sizeof(dp0));
        memcpy(dp1, ne1, sizeof(dp1));
    }
    int ans = ne0[m][k] + ne1[m][k];
    if (ans >= MOD) ans -= MOD;
    cout << ans;
    return 0;
}