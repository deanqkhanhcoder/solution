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
    static bool ip[181];
    memset(ip, 1, sizeof(ip));
    ip[0] = ip[1] = false;
    for (int i = 2; i * i <= 180; ++i){
        if (ip[i]){
            for (int j = i * i; j <= 180; j += i){
                ip[j] = false;
            }
        }
    }
    static ll dp[20][2][181];
    int n;
    string s;
    auto dfs = [&](auto &&self, int pos, bool smaller, int sum) -> ll {
        if (pos == n){
            return ip[sum];
        }
        ll &res = dp[pos][smaller][sum];
        if (res != -1) return res;
        int limit = (smaller ? 9 : s[pos] - '0');
        res = 0;
        for (int d = 0; d <= limit; ++d){
            bool nsmaller = smaller || (d < limit);
            res += self(self, pos + 1, nsmaller, sum + d);
        }
        return res;
    };
    auto calc = [&](ll val){
        memset(dp, -1, sizeof(dp));
        s = to_string(val);
        n = s.length();
        ll ans = dfs(dfs, 0, 0, 0);
        return ans;
    };
    auto solve = [&](ll k){
        ll lo = 1, hi = (ll)1e18;
        while (lo < hi){
            ll mid = (hi + lo) / 2;
            if (calc(mid) >= k) hi = mid;
            else lo = mid + 1;
            // cerr << "lo = " << lo << endl;
        }
        return lo;
    };
    int t; cin >> t;
    while(t--){
        ll k; cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}