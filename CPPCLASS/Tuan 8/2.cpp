#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    string k; cin >> k;
    int n = k.length();
    int m; cin >> m;
    static ll dp[100005][2][100];
    memset(dp, -1, sizeof(dp));
    auto dfs = [&](auto &&self, int pos, bool smaller, int sum) -> ll {
        if (pos == n){
            return (sum % m) == 0;
        }
        ll &res = dp[pos][smaller][sum];
        if (res != -1) return res;
        int limit = (smaller ? 9 : k[pos] - '0');
        res = 0;
        for (int d = 0; d <= limit; ++d){
            bool nsmaller = smaller || (d < limit);
            int nsum = (sum + d) % m;
            res += self(self, pos + 1, nsmaller, nsum);
            res %= MOD;
        }
        return res;
    };
    ll ans = dfs(dfs, 0, 0, 0);
    cout << ans - 1 << endl;
    return 0;
}