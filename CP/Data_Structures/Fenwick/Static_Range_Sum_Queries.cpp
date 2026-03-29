#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int a[n + 1];
    ll prefix[n + 1] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}