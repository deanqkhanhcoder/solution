#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
int solve(int x){
    for (int i = 2; i * i <= x; i++){
        int cnt = 0;
        while (x % i == 0){
            x /= i;
            cnt++;
        }
        if (cnt % 2 == 1) x *= i;
    }
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    int n; cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        int d = solve(x);
        mp[d]++;
    }
    ll ans = 0;
    for (auto &p : mp){
        ans += 1LL * p.first * (p.first - 1) / 2;
    }
    cout << ans;
    return 0;
}