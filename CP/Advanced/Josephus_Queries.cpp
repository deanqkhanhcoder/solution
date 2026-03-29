#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>,int> memo;

int solve(int n, int k) {
    if(memo.count({n, k})) return memo[{n, k}];
    if(n == 1) return memo[{n, k}] = 1;
    if(2*k <= n) return memo[{n, k}] = 2*k;
    int newn = (n + 1)/2;
    int newk = k - n/2;
    if(n & 1) {
        int ans = solve(newn, newk);
        return memo[{n, k}] = ((2*ans - 3) + (n + 1)) % (n + 1);
    } else {
        return memo[{n, k}] = 2 * solve(newn, newk) - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}
