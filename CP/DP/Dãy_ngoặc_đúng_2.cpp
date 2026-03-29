#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
constexpr int INF = (int)1e9;
bool check(char a, char b){
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    static int dp[101][101];
    for (int len = 1; len <= n; ++len){
        for (int l = 1; l + len - 1 <= n; ++l){
            int r = l + len - 1;
            if (l == r){
                dp[l][r] = 1;
                continue;
            }
            int ans = INF;
            for (int k = l + 1; k <= r; ++k){
                if (check(s[l], s[k])){
                    int t1 = (l + 1 <= k - 1 ? dp[l + 1][k - 1] : 0);
                    int t2 = (k + 1 <= r ? dp[k + 1][r] : 0);
                    ans = min(ans, t1 + t2);
                }
            }
            for (int k = l; k < r; ++k){
                ans = min(ans, dp[l][k] + dp[k + 1][r]);
            }
            ans = min(ans, 1 + dp[l + 1][r]);
            dp[l][r] = ans;
        }
    }
    cout << dp[1][n];
    return 0;
}