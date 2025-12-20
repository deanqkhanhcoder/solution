#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <string>
#include <cstring>
using namespace std;
using ll = long long;

string s;
int n;
ll dp[20][2][10];

ll dfs(int pos, bool smaller, int last) {
    if (pos == n) {
       return (last == 1 || last == 4 || last == 6 || last == 9);
    }
    ll &res = dp[pos][smaller][last];
    if (res != -1) return res;
    res = 0;
    int limit = smaller ? 9 : (s[pos] - '0');
    for (int d = 0; d <= limit; d++) {
        bool nsmaller = smaller || (d < limit);
        res += dfs(pos + 1, nsmaller, d);
    }
    return res;
}

ll solve(ll x) {
    s = to_string(x);
    n = (int)s.size();
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, r; cin >> l >> r;
    cout << solve(r) - solve(l - 1);
}
