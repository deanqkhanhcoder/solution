#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b; cin >> a >> b;
    int l = 1;
    int ans = 0;
    for (int i = a; i <= b; ++i){
        string s = to_string(i);
        for (char &c : s){
            if (l & 1 && c - '0' == 0) ans++;
            l++;
        }
    }
    cout << ans;
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// string s;
// int n;
// ll dp[20][2][2][2];

// ll dfs(int pos, bool smaller, bool ok, bool check) {
//     if (pos == n)
//         return 0;
//     ll &res = dp[pos][smaller][ok][check];
//     if (res != -1) return res;
//     res = 0;
//     int limit = smaller ? 9 : (s[pos] - '0');
//     for (int d = 0; d <= limit; d++) {
//         bool nok = ok || (d != 0);
//         bool ncheck = check;
//         bool nsmaller = smaller || (d < limit && !smaller);
//         if (nok) {
//             if (d == 0 && ncheck)
//                 res++;
//             ncheck ^= 1;
//         }
//         res += dfs(pos + 1, nsmaller, nok, ncheck);
//     }
//     return res;
// }

// ll solve(ll n) {
//     s = to_string(n);
//     n = (int)s.size();
//     memset(dp, -1, sizeof(dp));
//     return dfs(0, 0, 0, 1); 
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ll a, b;
//     cin >> a >> b;
//     cout << solve(b) - solve(a - 1);
//     return 0;
// }
