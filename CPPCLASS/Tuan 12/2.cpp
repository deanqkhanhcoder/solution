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
    vector<ll> tree, lazy;
    SegmentTree(int n) : n(n), tree(4 * n + 5), lazy(4 * n + 5) {}
    void build (int id, int l, int r, vector<int> &a){
        if (l == r){
            tree[id] = a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, a);
        build(2 * id + 1, mid + 1, r, a);
        tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
    void pushDown(int id, int l, int m, int r){
        if (lazy[id] == 0) return;
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
        tree[2 * id] += 1LL * lazy[id] * (m - l + 1);
        tree[2 * id + 1] += 1LL * lazy[id] * (r - m);
        lazy[id] = 0;
    }
    void update(int id ,int l, int r, int u, int v, ll x){
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            tree[id] += 1LL * x * (r - l + 1);
            lazy[id] += x;
            return;
        }
        int mid = (l + r) / 2;
        pushDown(id, l, mid, r);
        update(2 * id, l, mid, u, v, x);
        update(2 * id + 1, mid + 1, r, u, v, x);
        tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
    ll query(int id ,int l, int r, int u, int v){
        if (v < l || r < u) return 0;
        if (u <= l && r <= v){
            return tree[id];
        }
        int mid = (l + r) / 2;
        pushDown(id, l, mid, r);
        ll L = query(2 * id, l, mid, u, v);
        ll R = query(2 * id + 1, mid + 1, r, u, v);
        return L + R;
    }
    void build(vector<int> &a){
        build(1, 1, n, a);
    }
    void update(int u, int v, ll x){
        update(1, 1, n, u, v, x);
    }
    ll query(int u, int v){
        return query(1, 1, n, u, v);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    SegmentTree st(n);
    st.build(a);
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int u, v, x; cin >> u >> v >> x;
            st.update(u, v, x);
        } else if (type == 2){
            int u, v; cin >> u >> v;
            ll ans = st.query(u, v);
            cout << ans << endl;
        }
    }
    return 0;
}