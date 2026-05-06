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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i){
        ll con = (i + 1)*(n - i);
        cin >> a[i];
        a[i] *= con;
    }
    for (int i = 0; i < n; ++i) cin >> b[i];   
    sort(all(a));
    sort(all(b), greater<int>());
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        ans += 1LL * a[i] * b[i];
    }
    cout << ans;
    return 0;
}