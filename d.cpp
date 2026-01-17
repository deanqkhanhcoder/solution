#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
unordered_map<ll, ll> memo;

ll dfs(ll x){
    if (x < 12) return x;
    if (memo.count(x)) return memo[x];
    return memo[x] = max(x, dfs(x / 2) + dfs(x / 3) + dfs(x / 4));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int a; cin >> a;
        cout << dfs(a) << '\n';
    }
    return 0;
}