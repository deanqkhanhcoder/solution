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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    int needed = 0;
    for (int i = 0; i < n; ++i){
        needed = max(needed - m, a[i]);
        a[i] = needed;
    }
    needed = 0;
    for (int i = n - 1; i >= 0; --i){
        needed = max(needed - m, a[i]);
        a[i] = needed;
    }
    for (int e : a) cout << e << ' ';
}