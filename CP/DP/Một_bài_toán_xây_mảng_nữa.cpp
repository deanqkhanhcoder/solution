#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = (int) 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int maxs = 2 * k;
    vector<int> pr;
    pr.reserve(1000);
    vector<bool> ip(maxs + 1, true);
    ip[0] = ip[1] = false;
    for (int i = 2; i <= maxs; ++i){
        if (ip[i]) pr.push_back(i);
        for (int e : pr){
            if (i * e > maxs) break;
            ip[i * e] = false;
            if (i % e == 0) break;
        }
    }
    vector<vector<int>> adj(k + 1);
    for (int p : pr){
        for (int x = max(0, p - k); x <= min(p, k); ++x){
            int y = p - x;
            adj[x].push_back(y);
        }
    }
    vector<int> pre(k + 1, 1);
    vector<int> cur(k + 1, 0);
    for (int i = 2; i <= n; ++i) {
        fill(cur.begin(), cur.end(), 0);
        for (int x = 0; x <= k; ++x){
            ll sum = 0;
            for (int y : adj[x]) sum += pre[y];
            cur[x] = sum % MOD;
        }
        swap(pre, cur);
    }
    ll ans = 0;
    for (int x = 0; x <= k; ++x){
        ans = (ans + pre[x]);
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans;
    return 0;
}