#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll f(int s){
    if (s < 0 || s > 18) return 0;
    if (s <= 9) return s + 1;
    return 19 - s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n; cin >> n;
    int m = (int)n.size();
    vector<ll> dp(m + 1, 0);
    dp[m] = 1;
    for (int i = m - 1; i >= 0; --i){
        int s1 = n[i] - '0';
        dp[i] += (ll)f(s1) * dp[i + 1];
        if (s1 == 0) continue;
        if (i + 1 < m){
            int s2 = s1 * 10 + (n[i + 1] - '0');
            dp[i] += (ll)f(s2) * dp[i + 2];
        }
    }
    cout << dp[0];
    return 0;
}   