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
    int n; cin >> n;
    vector<int> a(n);
    // ll sum= 0;
    for (int &e : a) cin >> e;
    vector<int> f(n + 1, 0);
    ll ans = 0;
    ll curr = 0;
    for (int i = 0; i < n; ++i){
        curr += f[i];
        ll cost = a[i] - 1 - curr;
        ans += max(0LL, cost);
        if (i + 2 < n){
            int l = i + 2;
            f[l] += 1;
            int r = i + a[i] + 1;
            if (r < n) f[r] -= 1;
        }
        if (cost < 0){
            if (i + 1 < n){
                f[i + 1] += -(cost);
                if (i + 2 < n) f[i + 2] -= (-cost);
            }
        }
    }
    cout << ans;
}