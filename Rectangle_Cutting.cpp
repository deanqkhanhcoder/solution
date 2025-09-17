#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<int>> dp;
int f(int x, int y) {
    if (x == y) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    int res = INT_MAX;
    for (int k = 1; k <= x/2; k++) {
        res = min(res, f(k, y) + f(x-k, y) + 1);
    }
    for (int k = 1; k <= y/2; k++) {
        res = min(res, f(x, k) + f(x, y-k) + 1);
    }
    return dp[x][y] = res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b; cin >> a >> b;
    dp.assign(a + 1, vector(b + 1, -1));
    cout << f(a, b);
    return 0;
}