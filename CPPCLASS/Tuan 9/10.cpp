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
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    auto solve = [&](auto &&self, int l, int r, int base) -> int {
        if (l > r) return 0;
        int mn = a[l];
        for (int i = l + 1; i <= r; ++i) mn = min(mn, a[i]);
        int need = mn - base;
        int prev = l;
        for (int i = l; i <= r; ++i){
            if (a[i] == mn){
                need += self(self, prev, i - 1, mn);
                prev = i + 1;
            }
        }
        need += self(self, prev, r, need);
        return min(r - l + 1, need);
    };
    cout << solve(solve, 0, n - 1, 0) << endl;
    return 0;
}