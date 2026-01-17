#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int f(int s){
    if (s < 0 || s > 18) return 0;
    if (s <= 9) return s + 1;
    return 19 - s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    vector<ll> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i){
        int sum1 = s[i] - '0';
        dp[i] = 1LL * f(sum1) * dp[i + 1];
        if (i < n - 1){
            int sum2 = sum1 * 10 + s[i + 1] - '0';
            if (sum2 <= 18 && sum1 != 0){
                dp[i] += 1LL* f(sum2) * dp[i + 2];
            }
        }
    }
    cout << dp[0];
    return 0;
}
