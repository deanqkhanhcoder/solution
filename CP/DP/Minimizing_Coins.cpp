#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int &i : c) cin >> i;

    const int INF = INT_MAX;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int coin : c) {
        for (int i = coin; i <= x; i++) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);
}
