#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<int> dp(x+1, 0);
    for (int i = 0; i < n; ++i) {
        int cost = h[i];
        int cap = s[i];
        for (int w = x; w >= cost; --w) {
            dp[w] = max(dp[w], dp[w - cost] + cap);
        }
    }
    cout << dp[x];
    return 0;
}