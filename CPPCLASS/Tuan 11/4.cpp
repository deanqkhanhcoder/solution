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
struct SegmentTree {
    int n;
    vector<ll> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5, 0) {}
    void build(vector<ll> &a, int id, int l, int r){
        if (l == r){
            tree[id] = a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        tree[id] = tree[2 * id] + tree[2 * id + 1];
    } 
    void update(int id, int l, int r, int pos, ll val){
        if (l == r){
            tree[id] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid){
            update(2 * id, l, mid, pos, val);
        } else {
            update(2 * id + 1, mid + 1, r, pos, val);
        }
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
    ll query(int id, int l, int r, int u, int v){
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return tree[id];
        int mid = (l + r) / 2;
        return query(2 * id, l, mid, u, v) + query(2 * id + 1, mid + 1, r, u, v);
    }
    void build (vector<ll> &a){
        build(a, 1, 1, n);
    }
    void update(int pos, ll val) {
        update(1, 1, n, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<ll> diff(n);
    diff[0] = a[0];
    for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1];
    SegmentTree st(n);
    st.build(diff);
    while(q--){
        int type; cin >> type;
        if (type == 1){
            int u, v; cin >> u >> v;
            ll val; cin >> val;
            st.update(u, val);
            if (v + 1 <= n) st.update(v + 1, -val);
        } else if (type == 2){
            int k; cin >> k;
            ll res = st.query(1, k);
            cout << res << endl;
        }
    }
    return 0;
}