#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
ll dp[20][1 << 10][2][2];
string s;
int n;
ll dfs(int pos, int mask, bool smaller, int started){
    if (pos == n){
        return started;
    }
    ll &res = dp[pos][mask][smaller][started];
    if (res != -1) return res;
    res = 0;
    int limit = (smaller ? 9 : s[pos] - '0');
    for (int d = 0; d <= limit; ++d){
        bool nsmaller = smaller || (d < limit);
        if (started == 0 && d == 0){
            res += dfs(pos + 1, mask, nsmaller, 0);
        } else {
            if (mask & (1 << d)) continue;
            if (pos == n - 1 && d != 0 && d != 5) continue;
            int nmask = mask | (1 << d);
            res += dfs(pos + 1, nmask, nsmaller, 1);
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = (int)s.size();
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(0, 0, false, 0);
    cout << ans;
    return 0;
}