#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, D; cin >> n >> D;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    int r = 0;
    int ans = 1;
    for (int l = 0; l < n; ++l){
        while (r < n - 1 && a[r + 1] - a[l] <= D) r++;
        int len = r - l + 1;
        ans = (1LL * ans * len) % MOD;
    }
    cout << ans;
    return 0;
}