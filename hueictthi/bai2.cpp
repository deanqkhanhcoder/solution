#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
constexpr int MAXA = (int)1e6;
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int m, n; cin >> m >> n;
    bitset<MAXA + 1> ip;
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 4; i <= MAXA; i += 2) ip[i] = 0;
    for (int i = 3; i * i <= MAXA; i += 2){
        if (ip[i]){
            for (ll j = i * i; j <= MAXA; j += 2 * i){
                ip[j] = 0;
            }
        }
    }
    vector<vector<int>> ok(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            int a; cin >> a;
            int notp = 1 - ip[a];
            ok[i][j] = notp + ok[i][j - 1] + ok[i - 1][j] - ok[i - 1][j - 1];
        }
    }
    // for (int i = 1; i <= m; ++i){
    //     for (int j = 1; j <= n; ++j){
    //         cerr << ok[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int l = 1, r = min(m, n);
    while (l < r){
        int mid = (l + r + 1) / 2;
        bool check = false;
        for (int i = mid; i <= m; ++i){
            for (int j = mid; j <= n; ++j){
                int cnt = ok[i][j] - ok[i - mid][j] - ok[i][j - mid] + ok[i - mid][j - mid];
                if (cnt <= 1){
                    check = true;
                    break;
                }
            }
            if (check) break;
        }
        if (check) l = mid;
        else r = mid - 1;
    }
    cout << 1LL * l * l;
    return 0;
}