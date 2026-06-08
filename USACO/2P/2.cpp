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
constexpr int INF = 2e9 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    int l = 0;
    vector<int> ans(n, INF);
    for (int r = 0; r < n; ++r){
        while (l < (m - 1) && b[l + 1] <= a[r]) l++;
        ans[r] = min(ans[r], abs(a[r] - b[l]));
    }
    l = m - 1;
    for (int r = n - 1; r >= 0; --r){
        while (l > 0 && b[l - 1] >= a[r]) l--;
        ans[r] = min(ans[r], abs(b[l] - a[r]));
    }
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, ans[i]);
    cout << res;
}