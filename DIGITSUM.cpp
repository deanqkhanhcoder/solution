#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
ll dp[20][2][200];
string s;
int n;
ll f(int idx, bool smaller, int sum){
    if (idx == n) return sum;
    ll &memo = dp[idx][smaller][sum];
    if (memo != -1) return memo;
    int lim = smaller ? 9 : (s[idx] - '0');
    memo = 0;
    for (int d = 0; d <= lim; ++d){
        memo += f(idx + 1, smaller || (d < lim), sum + d);
    }

    
    return memo;
}
ll f(ll x){
    s = to_string(x);
    n = (int)s.size();
    memset(dp, -1, sizeof(dp));
    return f(0, 0, 0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    cout << f(b) - f(a - 1);
    return 0;
}