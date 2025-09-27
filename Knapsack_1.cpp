#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<ll> dp(w + 1);
    for (int i = 1; i <= n; ++i){
        int c, cap; cin >> c >> cap;
        for (int j = w; j >= c; --j){
            dp[j] = max(dp[j], dp[j - c] + cap);
        }
    }
    cout << dp[w];
    return 0;
}