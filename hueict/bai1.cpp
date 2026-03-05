#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d; cin >> a >> b >> c >> d;
    auto solve = [=](int n, int m){
        n = min(n, m - 1);
        ll res = 1LL * m * n - 1LL * (n + 1) * n / 2;
        return (res < 0 ? 0 : res);
    };
    ll ans = solve(b, d) - solve(a - 1, d) - solve(b, c - 1) + solve(a - 1, c - 1);
    cout << ans;
}