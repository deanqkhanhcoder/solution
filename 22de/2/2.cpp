#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, k;
    unordered_map<ll, ll> dp[25][200];
    auto clear = [&]{
        for (int i = 0; i < 25; ++i){
            for (int j = 0; j < 200; ++j){
                dp[i][j].clear();
            }
        }
    };
    auto dfs = [&](auto &&self, int pos, int sum, ll mask) -> ll {
        if (pos == n){
            if (sum & 1) return 1;
            if (mask & (1LL << (sum / 2))) return 0;
            return 1;
        }
        if (dp[pos][sum].count(mask)) return dp[pos][sum][mask];
        ll res = 0;
        for (int d = 0; d <= k; ++d){
            ll n_mask = mask | (mask << d);
            res += self(self, pos + 1, sum + d, n_mask);
        }
        return dp[pos][sum][mask] = res;
    };
    while(cin >> n >> k){
        clear();
        cout << dfs(dfs, 0, 0, 1) << endl;
    }
    return 0;
}