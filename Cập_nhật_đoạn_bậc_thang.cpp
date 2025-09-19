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
    vector<ll> g(n + 2, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        d[l] += 1;
        d[r + 1] -= 1;
        g[r + 1] -= (r - l + 1);
    }
    /*
    cout << "d : ";
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
    cout << "g : ";
    for (int i = 1; i <= n; i++) {
        cout << g[i] << " ";
    }
    */
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        g[i] += g[i - 1];
    }
    /*
    cout << "\n";
    cout << "d : ";
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
    cout << "g : ";
    for (int i = 1; i <= n; i++) {
        cout << g[i] << " ";
    }
    */
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        cout << d[i] + g[i] << " ";
    }
    return 0;
}
