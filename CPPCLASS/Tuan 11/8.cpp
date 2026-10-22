#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; 
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    const int LOG = __lg(n);
    vector<vector<pair<int, int>>> st(n, vector<pair<int, int>>(LOG + 1));
    for (int i = 0; i < n; ++i) {
        st[i][0] = {a[i], i};
    }
    for (int k = 1; k <= LOG; ++k) {
        for (int i = 0; i + (1 << k) <= n; ++i) {
            st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
    auto get_max = [&](int l, int r) -> pair<int, int> {
        if (l > r) return {-1, -1};
        int k = __lg(r - l + 1);
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    };
    while (q--) {
        int l, r; 
        cin >> l >> r;
        l--; r--;
        auto [mx1, pos] = get_max(l, r);
        int mx2 = max(get_max(l, pos - 1).first, get_max(pos + 1, r).first);
        cout << 1LL * mx1 + mx2 << endl;
    }
    return 0;
}