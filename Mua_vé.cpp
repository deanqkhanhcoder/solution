#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> t(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 2; i <= n; ++i) cin >> r[i];

    if (n == 1) {
        cout << t[1];
        return 0;
    }
    int dp1 = t[1];
    int dp2 = min(t[1] + t[2], r[2]);
    for (int i = 3; i <= n; ++i) {
        int cur = min(dp2 + t[i], dp1 + r[i]);
        dp1 = dp2;
        dp2 = cur;
    }
    cout << dp2;
    return 0;
}