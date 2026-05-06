#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
string s;
int n;
int k;
int memo[20][20][3];
int dfs(int pos, int usedk, int rem){
    if (pos == n){
        return (rem == 0);
    }
    if (memo[pos][usedk][rem] != -1) return memo[pos][usedk][rem];
    bool can = 0;
    for (int d = 0; d <= 9; ++d){
        if (pos == 0 && d == 0) continue;
        int cost = (d != s[pos] - '0');
        int ncost = usedk + cost;
        if (usedk + cost <= k){
            int nrem = (rem * 10 + d) % 3;
            if (dfs(pos + 1, ncost, nrem)){
                can = 1;
                break;
            }
        }
    }
    return memo[pos][usedk][rem] = can;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    cin >> s; cin >> k;
    n = (int)s.size();
    memset(memo, -1, sizeof(memo));
    dfs(0, 0, 0);
    if (!memo[0][0][0]){
        cout << 0;
        return 0;
    }
    int currk = 0;
    int curem = 0;
    string res = "";
    for (int i = 0; i < n; ++i){
        for (int d = 0; d <= 9; ++d){
            if (i == 0 && d == 0) continue;
            int cost = (d != s[i] - '0');
            int ncost = currk + cost;
            if (ncost <= k && dfs(i + 1, ncost, (curem * 10 + d) % 3)){
                res += to_string(d);
                currk = ncost;
                curem = (curem + d) % 3;
                break;
            }
        }
    }
    cout << res;
    return 0;
}