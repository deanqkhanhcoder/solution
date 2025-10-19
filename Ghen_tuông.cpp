#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    vector<vector<ll>> dp1(n, vector<ll>(2, 0));
    vector<vector<ll>> dp2(n, vector<ll>(2, 0));
    dp1[0][0] = a[0];
    dp2[0][0] = b[0];
    for (int i = 1; i < n; ++i){
        dp1[i][0] = max(dp2[i - 1][0], dp2[i - 1][1]) + a[i];
        dp1[i][1] = dp1[i - 1][0] + a[i];
        dp2[i][0] = max(dp1[i - 1][0], dp1[i - 1][1]) + b[i];
        dp2[i][1] = dp2[i - 1][0] + b[i];
    }
    ll ans = max({dp1[n - 1][0], dp1[n - 1][1], dp2[n - 1][0], dp2[n - 1][1]});
    cout << ans;
    return 0;
}