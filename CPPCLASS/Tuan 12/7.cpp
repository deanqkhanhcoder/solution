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
    ll sumSq = 0;
    ll mul = 1;
    ll add = 0;
};

struct SegmentTree {
    int n;
    vector<Node> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5) {}
    void apply(int id, int l, int r, ll mul, ll add) {
        ll len = r - l + 1;
        ll oldSum = tree[id].sum;
        ll oldSumSq = tree[id].sumSq;
        tree[id].sumSq =
            mul * mul * oldSumSq
            + 2LL * mul * add * oldSum
            + len * add * add
        tree[id].sum = mul * oldSum + len * add;
        tree[id].mul = mul * tree[id].mul;
        tree[id].add = mul * tree[id].add + add;
    }
    void pushDown(int id, int l, int mid, int r) {
        if (tree[id].mul == 1 && tree[id].add == 0)
            return;
        apply(2 * id, l, mid,
              tree[id].mul, tree[id].add);
        apply(2 * id + 1, mid + 1, r,
              tree[id].mul, tree[id].add);
        tree[id].mul = 1;
        tree[id].add = 0;
    }
    void pull(int id) {
        tree[id].sum =
            tree[2 * id].sum + tree[2 * id + 1].sum;
        tree[id].sumSq =
            tree[2 * id].sumSq + tree[2 * id + 1].sumSq;
    }
    void build(int id, int l, int r, const vector<ll>& a) {
        if (l == r) {
            tree[id].sum = a[l];
            tree[id].sumSq = a[l] * a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, a);
        build(2 * id + 1, mid + 1, r, a);
        pull(id);
    }

    void update(int id, int l, int r,
                int u, int v, ll mul, ll add) {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v) {
            apply(id, l, r, mul, add);
            return;
        }
        int mid = (l + r) / 2;
        pushDown(id, l, mid, r);
        update(2 * id, l, mid, u, v, mul, add);
        update(2 * id + 1, mid + 1, r, u, v, mul, add);
        pull(id);
    }

    ll query(int id, int l, int r, int u, int v) {
        if (v < l || r < u)
            return 0;
        if (u <= l && r <= v)
            return tree[id].sumSq;
        int mid = (l + r) / 2;
        pushDown(id, l, mid, r);
        return query(2 * id, l, mid, u, v)
             + query(2 * id + 1, mid + 1, r, u, v);
    }
    void build(const vector<ll>& a) {
        build(1, 1, n, a);
    }
    void add(int u, int v, ll x) {
        update(1, 1, n, u, v, 1, x);
    }
    void assign(int u, int v, ll x) {
        update(1, 1, n, u, v, 0, x);
    }
    ll query(int u, int v) {
        return query(1, 1, n, u, v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    SegmentTree st(n);
    st.build(a);

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 2) {
            cout << st.query(u, v) << '\n';
        } else {
            ll x;
            cin >> x;
            if (type == 1)
                st.add(u, v, x);
            else
                st.assign(u, v, x);
        }
    }

    return 0;
}
