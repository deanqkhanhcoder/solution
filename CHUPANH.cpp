#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; 
    cin >> n >> k;
    int lmask = (k << 1) + 1;
    int MASK = (1 << lmask);
    int smask = 0;
    for (int i = 0; i < n; ++i){
        int ok = i - k;
        if (ok < 0){
            smask |= (1 << i);
        } else {
            break;
        }
    }
    vector<ll> dp1(MASK, 0);
    vector<ll> dp2(MASK, 0);
    dp1[smask] = 1;
    for (int i = 0; i < n; ++i){
        memset(dp2.data(), 0, MASK * sizeof(ll));
        for (int mask = 0; mask < MASK; ++mask){
            if (dp1[mask] == 0) continue;
            for (int j = 0; j < lmask; ++j){
                if (mask & (1 << j)) continue;
                int ok = i + (j - k);
                if (ok < 0 || ok > n - 1) continue;
                int temp = mask | (1 << j);
                if ((temp & 1) == 0) continue;
                int next = temp >> 1;
                ok = i + k;
                if (ok >= n - 1){
                    next |= (1 << (lmask - 1));
                }
                dp2[next] += dp1[mask];
                if (dp2[next] >= MOD) dp2[next] -= MOD;
            }
        }
        swap(dp1, dp2);
    }
    ll ans = 0;
    for (int i = 0; i < MASK; ++i){
        ans += dp1[i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans;
    return 0;
}