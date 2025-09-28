#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> dp(2, vector<int>(3, 0));
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    n--;
    while (n--){
        int a, b, c; cin >> a >> b >> c;
        dp[1][0] = max(dp[0][1], dp[0][2]) + a;
        dp[1][1] = max(dp[0][0], dp[0][2]) + b;
        dp[1][2] = max(dp[0][0], dp[0][1]) + c;
        swap(dp[0], dp[1]);
    }
    cout << max(dp[0][0] ,max(dp[0][1] ,dp[0][2]));
    return 0;
}