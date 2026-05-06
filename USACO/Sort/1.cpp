#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 1e15;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
    int N = 2 * n;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<long long>> dp(N + 1, vector<long long>(3, INF));
 
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 2; j++) {
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            if (i >= 2) {
                dp[i][j] = min(dp[i][j], dp[i - 2][j] + (a[i - 1] - a[i - 2]));
            }
        }
    }
    cout << dp[N][2] << endl;
    return 0;
}