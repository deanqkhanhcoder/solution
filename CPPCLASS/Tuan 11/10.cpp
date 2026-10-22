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
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;
struct Node {
    ll x, y;
};
Node merge(Node a, Node b) {
    return {min(a.x, b.x), min(a.y, b.y)};
}
struct SegmentTree {
    int n;
    vector<Node> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5, {INFLL, INFLL}) {}
    void build(vector<ll>& a, int id, int l, int r) {
        if (l == r) {
            tree[id] = {a[l] - l, a[l] + l};
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    void update(int id, int l, int r, int pos, ll val) {
        if (l == r) {
            tree[id] = {val - pos, val + pos};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * id, l, mid, pos, val);
        else update(2 * id + 1, mid + 1, r, pos, val);
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    Node query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return {INFLL, INFLL};
        if (u <= l && r <= v) return tree[id];
        int mid = (l + r) / 2;
        return merge(
            query(2 * id, l, mid, u, v),
            query(2 * id + 1, mid + 1, r, u, v)
        );
    }
    void build(vector<ll> &a){
        build(a, 1, 1, n);
    }
    void update(int pos, ll val){
        update(1, 1, n, pos, val);
    }
    Node query(int u, int v){
        if (u > v) return {INFLL, INFLL};
        return query(1, 1, n, u, v);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, q; cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SegmentTree st(n);
    st.build(a);
    while(q--){
        int type; cin >> type;
        if (type == 1){
            int k; ll x; cin >> k >> x;
            a[k] = x;
            st.update(k, x);
        } else if (type == 2){
            int k; cin >> k;
            ll first = st.query(1, k - 1).x + k;
            ll second = st.query(k + 1, n).y - k;
            cout << min({a[k], first, second}) << endl;
        }
    }
    return 0;
}