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
struct Node {
    ll sum = 0;
    ll lazyP = 0, lazyQ = 0;
};
struct SegmentTree {
    int n;
    vector<Node> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5) {}
    void build(int id, int l, int r, vector<int> &a){
        if (l == r){
            tree[id].sum = a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, a);
        build(2 * id + 1, mid + 1, r, a);
        tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
    }
    void apply(int id, int l, int r, ll p, ll q){
        int len = r - l + 1;
        tree[id].sum += 1LL * p * len * (l + r) / 2
                        + 1LL * q * len;
        tree[id].lazyP += p; 
        tree[id].lazyQ += q; 
    }
    void pushDown(int id, int l, int m, int r) {
        ll p = tree[id].lazyP;
        ll q = tree[id].lazyQ;
        apply(2 * id, l, m, p, q);
        apply(2 * id + 1, m + 1, r, p, q);
        tree[id].lazyP = 0;
        tree[id].lazyQ = 0;
    }
    void update(int id, int l, int r, int u, int v, ll p, ll q){
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            apply(id, l, r, p, q);
            return;
        }
        int mid = (l + r) / 2;
        pushDown(id, l, mid, r);
        update(2 * id, l, mid, u, v, p, q);
        update(2 * id + 1, mid + 1, r, u, v, p, q);
        tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
    }
    ll query(int id, int l, int r, int u, int v){
        if (v < l || r < u) return 0;
        if (u <= l && r <= v){
            return tree[id].sum;
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
    void update(int u, int v){
        update(1, 1, n, u, v, 1, 1 - u);
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
    while(q--){
        int type, a, b; cin >> type >> a >> b;
        if (type == 1) st.update(a, b);
        else cout << st.query(a, b) << endl;
    }
    return 0;
}