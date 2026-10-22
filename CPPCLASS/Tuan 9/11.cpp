#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    auto solve = [&](auto &&self, int x, int y){
        if (x == y) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        int res = INF;
        for (int k = 1; k <= x / 2; ++k){
            res = min(res, self(self, x - k, y) + self(self, k, y) + 1);
        }
        for (int k = 1; k <= y / 2; ++k){
            res = min(res, self(self, x, y - k) + self(self, x, k) + 1);
        }
        return dp[x][y] = res;
    };
    cout << solve(solve, a, b) << endl;
    return 0;
}