#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int T; cin >> T;
    while (T--){
        int M, N; cin >> M >> N;
        if (M < N) swap(M, N);
        int limit = 1 << N;
        if (N == 1){
            cout << (1LL << M) << '\n';
            continue;
        }
        vector<vector<int>> good(limit);
        for (int mask1 = 0; mask1 < limit; ++mask1){
            for (int mask2 = 0; mask2 < limit; ++mask2){
                bool bad = false;
                for (int i = 0; i < N - 1; ++i){
                    bool a = (mask1 >> i) & 1;
                    bool b = (mask1 >> (i + 1)) & 1;
                    bool c = (mask2 >> i) & 1;
                    bool d = (mask2 >> (i + 1)) & 1;
                    if (a == b && a == c && a == d){
                        bad = true;
                        break;
                    }
                }
                if (!bad){
                    good[mask2].push_back(mask1);
                }
            }
        }
        vector<ll> pre(limit, 1), dp(limit);
        for (int i = 2; i <= M; ++i){
            memset(dp.data(), 0, dp.size() * sizeof(ll));
            for (int mask2 = 0; mask2 < limit; ++mask2){
                for (int &mask1 : good[mask2]){
                    dp[mask2] += pre[mask1];
                }
            }
            swap(dp, pre);
        }
        ll ans = 0;
        for (int mask = 0; mask < limit; ++mask){
            ans += pre[mask];
        }
        cout << ans << '\n';
    }
    return 0;
}