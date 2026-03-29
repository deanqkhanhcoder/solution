#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<double> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) dp[i][j] = dp[i-1][j] * (1 - p[i]);
            else dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
        }
    }
    double result = 0;
    for (int j = n / 2 + 1; j <= n; ++j) {
        result += dp[n][j];
    }
    cout << fixed << setprecision(10) << result << endl;
    return 0;
}