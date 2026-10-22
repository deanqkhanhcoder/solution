#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; 
    if (!(cin >> n)) return 0;

    int time_tag = 0;
    string s;
    int m;
    int target;
    static ll dp[15][2][95][95];
    static int vis[15][2][95][95];

    auto dfs = [&](auto &&self, int pos, bool smaller, int mul, int sum, int len) -> ll {
        if (sum > target) return 0;
        int rem = len - pos;
        if (sum + 9 * rem < target) return 0;
        
        if (pos == len) {
            return (sum == target && mul == 0) ? 1 : 0;
        }

        ll &res = dp[pos][smaller][mul][sum];
        if (vis[pos][smaller][mul][sum] == time_tag) return res;

        int limit = smaller ? 9 : (s[pos] - '0');
        res = 0;

        for (int d = 1; d <= limit; ++d) {
            bool nsmaller = smaller || (d < limit);
            int nmul = (mul * d) % target;
            int nsum = sum + d;
            res += self(self, pos + 1, nsmaller, nmul, nsum, len);
        }

        vis[pos][smaller][mul][sum] = time_tag;
        return res;
    };

    auto count_no_zero = [&](auto &&self, int pos, bool smaller) -> ll {
        if (pos == m) return 1;
        int limit = smaller ? 9 : (s[pos] - '0');
        ll ans = 0;
        for (int d = 1; d <= limit; ++d) {
            ans += self(self, pos + 1, smaller || (d < limit));
        }
        return ans;
    };

    // Đếm số lượng không chứa '0' trong [1, val]
    auto get_no_zero = [&](ll val) -> ll {
        ll total = 0;
        ll p9 = 9;
        for (int len = 1; len < m; ++len) {
            total += p9;
            p9 *= 9;
        }
        total += count_no_zero(count_no_zero, 0, false);
        return total;
    };

    auto calc = [&](ll val) -> ll {
        if (val <= 0) return 0;
        s = to_string(val);
        m = s.length();

        // 1. Số chứa ít nhất một chữ số 0 luôn thỏa mãn
        ll ans = val - get_no_zero(val);

        // 2. Các số không chứa chữ số 0 và (tích % tổng == 0)
        for (int sum_target = 1; sum_target <= 9 * m; ++sum_target) {
            target = sum_target;
            
            // Độ dài < m
            for (int len = 1; len < m; ++len) {
                time_tag++;
                ans += dfs(dfs, 0, true, 1 % target, 0, len);
            }
            // Độ dài == m
            time_tag++;
            ans += dfs(dfs, 0, false, 1 % target, 0, m);
        }
        return ans;
    };

    auto solve = [&](ll target_n) -> ll {
        ll lo = 1, hi = 2e9, ans = hi;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (calc(mid) >= target_n) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    };

    cout << solve(n) << "\n";
    return 0;
}