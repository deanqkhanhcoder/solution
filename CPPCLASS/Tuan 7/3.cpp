#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;
constexpr int MAX_SUM = 1458;
constexpr int MAX_N = 18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    auto next = [](int n){
        int sum = 0;
        while(n){
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    };
    vector<bool> is_happy(MAX_SUM + 1, false);
    for (int i = 1; i <= MAX_SUM; ++i){
        int slow = i, fast = i;
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast && slow != 1 && fast != 1);
        is_happy[i] = (slow == 1 || fast == 1);
    }
    vector<vector<ll>> ways(MAX_N + 1, vector<ll>(MAX_SUM + 1, 0));
    ways[0][0] = 1;
    for (int len = 1; len <= 18; ++len){
        for (int sum_sq = 0; sum_sq <= MAX_SUM; ++sum_sq){
            if (ways[len - 1][sum_sq] == 0) continue;
            for (int d = 0; d <= 9; ++d){
                if (sum_sq + d * d > MAX_SUM) break;
                ways[len][sum_sq + d * d] += ways[len - 1][sum_sq];
            }
        }
    }
    auto solve = [&](ll n) -> ll {
        if (n <= 0) return 0;
        string s = to_string(n);
        int m = s.length();
        ll ans = 0;
        int pref = 0;
        for (int i = 0; i < m; ++i){
            int limit = s[i] - '0';
            int rem_len = m - i - 1;
            for (int d = 0; d < limit; ++d){
                int cur = pref + d * d;
                int range = 81 * rem_len;              
                for (int suf = 0; suf <= range; ++suf){
                    int total = cur + suf;
                    if (total > MAX_SUM) break;
                    if (is_happy[total]) ans += ways[rem_len][suf];
                }
            }
            pref += limit * limit;
        }
        if (pref <= MAX_SUM && is_happy[pref]) ans++;
        return ans;
    };
    auto get = [&](ll l, ll r){
        ll range = r - l + 1;
        ll is_happy_cnt = solve(r) - solve(l - 1);
        return range - is_happy_cnt;
    };
    int t; cin >> t;
    while (t--){
        ll l, r; cin >> l >> r;
        cout << get(l, r) << endl;
    }
    return 0;
}