
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll sum = 0;
    ll mul = 1, add = 0;
};

struct SegmentTree {
    int n;
    vector<Node> st;

    SegmentTree(vector<ll>& a) {
        n = (int)a.size() - 1;
        st.resize(4 * n + 5);
        build(1, 1, n, a);
    }

    void build(int id, int l, int r, vector<ll>& a) {
        if (l == r) {
            st[id].sum = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid, a);
        build(id * 2 + 1, mid + 1, r, a);
        pull(id);
    }

    void pull(int id) {
        st[id].sum = st[id * 2].sum
                   + st[id * 2 + 1].sum;
    }

    void apply(int id, int l, int r, ll m, ll c) {
        st[id].sum = m * st[id].sum
                   + c * (r - l + 1LL);

        st[id].mul = m * st[id].mul;
        st[id].add = m * st[id].add + c;
    }

    void push(int id, int l, int r) {
        if (l == r) return;
        if (st[id].mul == 1 && st[id].add == 0)
            return;

        int mid = (l + r) / 2;

        apply(id * 2, l, mid,
              st[id].mul, st[id].add);

        apply(id * 2 + 1, mid + 1, r,
              st[id].mul, st[id].add);

        st[id].mul = 1;
        st[id].add = 0;
    }

    void update(int id, int l, int r,
                int u, int v, ll m, ll c) {
        if (v < l || r < u) return;

        if (u <= l && r <= v) {
            apply(id, l, r, m, c);
            return;
        }

        push(id, l, r);

        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, m, c);
        update(id * 2 + 1, mid + 1, r, u, v, m, c);

        pull(id);
    }

    ll query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;

        if (u <= l && r <= v)
            return st[id].sum;

        push(id, l, r);

        int mid = (l + r) / 2;
        return query(id * 2, l, mid, u, v)
             + query(id * 2 + 1, mid + 1, r, u, v);
    }

    void update(int l, int r, ll m, ll c) {
        update(1, 1, n, l, r, m, c);
    }

    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree seg(a);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            ll x;
            cin >> x;
            seg.update(a, b, 1, x);
        }
        else if (type == 2) {
            ll x;
            cin >> x;
            seg.update(a, b, 0, x);
        }
        else {
            cout << seg.query(a, b) << '\n';
        }
    }

    return 0;
}
