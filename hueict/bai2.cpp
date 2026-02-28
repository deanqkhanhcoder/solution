#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
ll dp[20][1 << 10][2][2];
string n;
int m;
ll dfs(int pos, int mask, bool smaller, bool started){
    if (pos == m){
        return 0;
    }
    ll &res = dp[pos][mask][smaller][started];
    if (res != -1) return dp[pos][mask][smaller][started];
    res = 0;
    int limit = (smaller ? 9 : n[pos] - '0');
    for (int d = 0; d <= limit; ++d){
        bool nsmaller = smaller || (d < limit);
        if (d == 0 && !started){
            res += dfs(pos + 1, mask, nsmaller, 0);
        } else {
            if ((mask >> d) & 1) continue;
            int nmask = mask | (1 << d);
            if (pos == m - 1 && (d == 0 || d == 5)){
                res++;
            } else {
                res += dfs(pos + 1, nmask, nsmaller, 1); 
            }
        }
    }
    return res = dp[pos][mask][smaller][started];
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    m = n.size();
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(0, 0, 0, 0);
    cout << ans;
}