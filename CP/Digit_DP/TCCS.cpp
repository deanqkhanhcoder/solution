#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
string s;
ll k;
int m;
pair<ll, ll> dp[15][100005][2];
bool vis[15][100005][2];
int d(ll i){
    int res = 0;
    while (i > 0){
        res += i % 10;
        i /= 10;
    }
    return res;
}
pair<ll, ll> dfs(int pos, int mod, bool smaller){
    if (pos == m){
        return make_pair(mod == 0, 0);
    }
    if (vis[pos][mod][smaller]) return dp[pos][mod][smaller];
    vis[pos][mod][smaller] = 1;
    pair<ll, ll> ans = {0, 0};
    int limit = (smaller ? 9 : s[pos] - '0');
    for (int d = 0; d <= limit; ++d){
        int nmod = (mod * 10 + d) % k;
        bool nsmaller = smaller || (d < limit);
        pair<ll, ll> child = dfs(pos + 1, nmod, nsmaller);
        ans.first += child.first;
        ans.second += child.second + d*child.first;
    }
    return dp[pos][mod][smaller] = ans;
}
void solve(ll n){
    s = to_string(n);
    m = s.size();
    memset(vis, 0, sizeof(vis));
    if (k <= 100000){
        pair<ll, ll> res = dfs(0, 0, 0);
        cout << res.second << '\n';
    } else {
        ll res = 0;
        for (ll i = k; i <= n; i += k){
            res += d(i);
        }
        cout << res << '\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    for (int i = 0; i < 2; ++i){
        ll n; cin >> n >> k;
        solve(n);
    }
}