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
struct SegmentTree{
    int n;
    vector<int> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5, 0) {}
    void build(const vector<int> &a, int id, int l, int r){
        if (l == r) {
            tree[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        tree[id] = min(tree[2 * id], tree[2 * id + 1]);
    }
    void update(int id, int l, int r, int pos, int val){
        if (l == r){
            tree[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * id, l, mid, pos, val);
        else update(2 * id + 1, mid + 1, r, pos, val);
        tree[id] = min(tree[2 * id], tree[2 * id + 1]);
    }
    int query(int id, int l, int r, int u, int v){
        if (v < l || r < u) return INF;
        if (u <= l && r <= v) return tree[id];
        int mid = (l + r) / 2;
        return min(query(2 * id, l, mid, u, v), query(2 * id + 1, mid + 1, r, u, v));
    }
    void build(vector<int> &a){
        build(a, 1, 1, n);
    }
    void update(int pos, int val){
        update(1, 1, n, pos, val);
    }
    int query(int u, int v){
        return query(1, 1, n, u, v);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SegmentTree st(n);
    st.build(a);
    while(q--){
        int type; cin >> type;
        if (type == 1){
            int k, V; cin >> k >> V;
            st.update(k, V);
        } else {
            int u, v; cin >> u >> v;
            cout << st.query(u, v) << endl;
        }
    }
    return 0;
}