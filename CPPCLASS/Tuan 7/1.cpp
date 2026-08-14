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
struct node {
    ll cnt, sum;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int t; cin >> t;
    string s; int n;
    static node dp[20][2];
    static bool vis[20][2];
    auto dfs = [&](auto &&self, int pos, bool smaller) -> node {
        if (pos == n){
            return {1, 0};
        }
        if (vis[pos][smaller]) return dp[pos][smaller];
        int limit = (smaller ? 9 : s[pos] - '0');
        ll cnt = 0, sum = 0;
        for (int d = 0; d <= limit; ++d){
            bool next_smaller = (smaller || d < limit);
            auto [s_cnt, s_sum] = self(self, pos + 1, next_smaller);
            cnt += s_cnt;
            sum += s_sum + 1LL * d * s_cnt;
        }
        vis[pos][smaller] = true;
        return dp[pos][smaller] = {cnt, sum};
    };
    auto solve = [&](ll x){
        memset(vis, false, sizeof(vis));
        s = to_string(x);
        n = s.length();
        node ans = dfs(dfs, 0, 0);
        return ans.sum;
    };
    while(t--){
        ll a, b; cin >> a >> b;
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}