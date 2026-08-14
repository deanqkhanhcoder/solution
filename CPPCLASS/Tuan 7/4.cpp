#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <string>
#define endl '\n'
#define DEBUG(x) cerr << "[DEBUG] " << #x << " = " << x << '\n' 
using namespace std;
using ull = unsigned long long;
using ll = long long;
constexpr int MOD = (int)1e9 + 9;
constexpr int MAX_N = 20;
constexpr ull HI_VAL = 18000000000000000000ULL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solve = [&](ull K, int m, int p){
        vector<vector<ull>> ways(MAX_N + 1, vector<ull>(m, 0));
        vector<vector<ull>> sum(MAX_N + 1, vector<ull>(m, 0));
        vector<ull> pow_10(MAX_N + 1);
        pow_10[0] = 1;
        for (int i = 1; i <= MAX_N; ++i) pow_10[i] = (pow_10[i - 1] * 10) % MOD; 
        ways[0][0] = 1;
        for (int len = 1; len <= MAX_N; ++len){
            vector<ull> d_pow(10);
            for (int d = 0; d < 10; ++d) d_pow[d] = (d * pow_10[len - 1]) % MOD;
            for (int r = 0; r < m; ++r){
                if (ways[len - 1][r] == 0) continue;
                for (int d = 0; d <= 9; ++d){
                    int nr = (r + d) % m;
                    ways[len][nr] += ways[len - 1][r];
                    sum[len][nr] += (ull)(((__int128)d_pow[d] * ways[len - 1][r]) % MOD) + sum[len - 1][r];
                    sum[len][nr] %= MOD;
                }
            }
        }
        auto dfs = [&](ull x, int target) -> pair<ull, ull> {
            string s = to_string(x);
            int n = s.length();
            ull cnt = 0;
            ull total = 0;
            int pref_r = 0;
            ull pref_val = 0;
            for (int i = 0; i < n; ++i){
                int limit = s[i] - '0';
                int rem_len = n - i - 1;
                for (int d = 0; d < limit; ++d){
                    int nr = (pref_r + d) % m;
                    int need = (target - nr + m) % m;
                    ull np = (pref_val * 10 + d) % MOD;
                    cnt += ways[rem_len][need];
                    ull contribution = (ull)(((__int128)np * ways[rem_len][need] % MOD) * pow_10[rem_len] % MOD) + sum[rem_len][need];  
                    total = (total + contribution) % MOD;
                }
                pref_r = (pref_r + limit) % m;
                pref_val = (pref_val * 10 + limit) % MOD;
            }
            if (pref_r == target){
                cnt++;
                total = (total + pref_val) % MOD;
            }
            return {cnt, total};
        };
        auto get1 = [&](ull x) -> pair<ull, ull> {
            auto [cnt, total] = dfs(x, 0);
            cnt--;
            return {cnt, total};
        };
        auto get2 = [&](ull x) -> pair<ull, ull> {
            if (x < (ull)p) return {0, 0};
            ull cnt = (x - p) / 10 + 1;
            if (p == 0) cnt--;
            if (cnt == 0) return {0, 0};
            ull total = 0;
            if (p == 0) {
                total = (ull)((__int128)(cnt % MOD) * ((cnt + 1) % MOD) % MOD * 5 % MOD);
            } else {
                total = (ull)((__int128)(cnt % MOD) * p % MOD);
                total += (ull)((__int128)(cnt % MOD) * ((cnt - 1) % MOD) % MOD * 5 % MOD);
            }
            total %= MOD;
            return {cnt, total};
        }; 
        auto get3 = [&](ull x) -> pair<ull, ull> {
            if (x < (ull)p){
                return {0, 0};
            }
            ull lb = (x - p) / 10;
            int target = (m - p % m) % m;
            auto [cnt, sum] = dfs(lb, target);
            if (p == 0){
                cnt--;
            }
            ull total = (10ULL * sum) % MOD + (ull)(((__int128)p * cnt) % MOD);
            total %= MOD;
            return {cnt, total};
        };
        auto calc = [&](ull x) -> pair<ull, ull> {
            pair<ull, ull> res1 = get1(x);  
            pair<ull, ull> res2 = get2(x);  
            pair<ull, ull> res3 = get3(x);  
            pair<ull, ull> ans = {0, 0};
            ans.first = res1.first + res2.first - res3.first;
            ll s1 = res1.second, s2 = res2.second, s3 = res3.second;
            ll s_tot = (s1 + s2 - s3) % (ll)MOD;
            if (s_tot < 0) s_tot += MOD;
            ans.second = s_tot;
            return ans;
        };

        ull lo = 1; 
        ull hi = HI_VAL;
        pair<ull, ull> cur;
        while (lo < hi){
            ull mid = lo + (hi - lo) / 2;
            cur = calc(mid);
            if (cur.first >= K) hi = mid;
            else lo = mid + 1;
        }
        cur = calc(lo);
        cout << lo << ' ' << cur.second << endl;
    };

    int q; cin >> q;
    while (q--){
        ull K; int m, p; cin >> K >> m >> p;
        solve(K, m, p);
    }
    return 0;
}
