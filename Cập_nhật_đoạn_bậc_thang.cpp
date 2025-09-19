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
    while (q--) {
        int l, r;
        cin >> l >> r;
        d[l] += 1;
        d[r + 1] -= (r - l + 2);
    }
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
