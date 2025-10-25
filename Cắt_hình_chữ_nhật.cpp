#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int INF = (int)1e9;
int a, b;
int dp[501][501] = {0};
int f(int x, int y){
    if (x == y) return 0;
    if (dp[x][y] != 0) return dp[x][y];
    int res = INF;
    for (int k = 1;k <= x/2; ++k) res = min(res, f(k, y) + f(x-k, y) + 1);
    for (int k = 1;k <= y/2; ++k) res = min(res, f(x, k) + f(x, y-k) + 1);
    return dp[x][y] = res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    cout << f(a, b);
}