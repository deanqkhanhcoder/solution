#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int w, a, b; cin >> w >> a >> b;
    vector<array<bool, 2>> dp(w + 1, {false, false});
    dp[0][0] = true;
    dp[0][1] = true;
    for (int i = 0; i <= w; ++i){
        if (!dp[i][0]) continue;
        if (i + a <= w){
            dp[i + a][0] = true;
            dp[(i + a) / 2][1] = true;
        }
        if (i + b <= w){
            dp[i + b][0] = true;
            dp[(i + b) / 2][1] = true;
        }
    }
    for (int i = 0; i <= w; ++i){
        if (!dp[i][1]) continue;
        if (i + a <= w){
            dp[i + a][1] = true;
        }
        if (i + b <= w){
            dp[i + b][1] = true;
        }    
    }
    for (int i = w; i >= 0; --i){
        if (dp[i][0] == true || dp[i][1] == true){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}