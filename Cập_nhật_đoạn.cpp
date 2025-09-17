#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<ll> d(n + 2, 0);
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        d[l] += 1;
        d[r + 1] -= 1;
    }
    
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + d[i];
        cout << a[i] << " ";
    }
    return 0;
}
