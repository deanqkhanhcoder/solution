#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
using namespace std;
using ll = long long;
constexpr ll INF = (ll)1e18;
ll dp[1 << 15][15];
int c[15][15];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    int FULL = (1 << n);
    for(int mask = 0; mask < FULL; mask++)
        for(int i = 0; i < n; i++)
            dp[mask][i] = INF;
    for(int i = 0; i < n; i++)
        dp[1 << i][i] = 0;
    for(int mask = 0; mask < FULL; mask++){
        for(int u = 0; u < n; u++){
            if(!(mask & (1 << u))) continue;
            if(dp[mask][u] == INF) continue;
            for(int v = 0; v < n; v++){
                if(mask & (1 << v)) continue;
                int nmask = mask | (1 << v);
                dp[nmask][v] = min(dp[nmask][v],dp[mask][u] + c[u][v]);
            }
        }
    }
    ll ans = INF;
    for(int u = 0; u < n; u++)
        ans = min(ans, dp[FULL-1][u]);
    cout << ans;
    return 0;
}
