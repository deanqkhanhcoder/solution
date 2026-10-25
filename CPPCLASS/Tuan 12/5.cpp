#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;
struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1) {}
    void add(int i, int x){
        for (; i <= n; i += lowbit(i))
            tree[i] += x;
    }
    int sum(int i){
        int res = 0;
        for (; i > 0; i -= lowbit(i))
            res += tree[i];
        return res;
    }
    int query(int l, int r){
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    const int MAXA = (int)1e6;
    vector<vector<pair<int, int>>> queries(n + 1);
    for (int i = 0; i < q; ++i){
        int l, r; cin >> l >> r;
        queries[r].push_back({l, i});
    }
    FenwickTree ft(n);
    vector<int> last(MAXA + 1);
    vector<int> ans(q);
    for (int r = 1; r <= n; ++r){
        int x = a[r];
        if (last[x]){
            ft.add(last[x], -1);
        }
        ft.add(r, 1);
        last[x] = r;
        for (auto [l, id] : queries[r]){
            ans[id] = ft.query(l, r);
        }
    }
    for (int x : ans) cout << x << endl;
    return 0;
}