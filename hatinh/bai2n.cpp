#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int LIMIT = (int)1e6;
int main(){
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int n; cin >> n;
    // vector<int> a(n), b(n), k(n);
    // for (int i = 0; i < n; ++i){
    //     int ai, bi, ki;
    //     cin >> ai >> bi >> ki;
    //     a[i] = ai;
    //     b[i] = bi;
    //     k[i] = ki;
    // }
    vector<int> cnt(LIMIT + 1, 0);
    for (int i = 2; i <= LIMIT; ++i){
        if (cnt[i] == 0){
            for (int j = i; j <= LIMIT; j += i){
                cnt[j]++;
            }
        }
    }
    vector<vector<int>> pref(LIMIT + 1, vector<int>(8, 0));
    for (int a = 2; a <= LIMIT; ++a){
        for (int k = 1; k <= 7; ++k){
            pref[a][k] = pref[a - 1][k] + (cnt[a] >= k);
        }
    }
    // for (int a = 2; a <= LIMIT; ++a){
    //     pref[a][0] = a;
    // }
    int q; cin >> q;
    while (q--){
        int a, b, k;
        cin >> a >> b >> k;
        if (k == 0){
            cout << b - a + 1 << '\n';
            continue;
        }
        cout << pref[b][k] - pref[a - 1][k] << '\n';
    }
    return 0;
}