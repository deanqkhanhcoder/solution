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
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int K = __lg(n);
    vector<vector<int>> rmq(n, vector<int>(K + 1));
    for (int i = 0; i < n; ++i) rmq[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j){
        for (int i = 0; i + (1 << j) <= n; ++i){
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        l--; r--;
        int len = r - l + 1;
        int k = __lg(len);
        int ans = min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
        cout << ans << endl;
    }
    return 0;
}