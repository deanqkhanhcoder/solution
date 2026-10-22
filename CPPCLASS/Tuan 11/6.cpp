
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

struct Node{
    char type;
    ll first, second;
};

struct SegmentTree{
    int n;
    vector<ll> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5) {}
    void update(int id, int l, int r, int pos, ll val){
        if (l == r) {
            tree[id] += val;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * id, l, mid, pos, val);
        else update(2 * id + 1, mid + 1, r, pos, val);

        tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
    ll query(int id, int l, int r, int u, int v){
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return tree[id];

        int mid = (l + r) / 2;
        return query(2 * id, l, mid, u, v)
             + query(2 * id + 1, mid + 1, r, u, v);
    }
    void update(int pos, ll val){
        update(1, 1, n, pos, val);
    }
    ll query(int u, int v){
        if (u > v) return 0;
        return query(1, 1, n, u, v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> p(n);
    vector<ll> v;
    for (ll &x : p){
        cin >> x;
        v.push_back(x);
    }
    vector<Node> queries(q);
    for (int i = 0; i < q; ++i){
        cin >> queries[i].type;
        cin >> queries[i].first >> queries[i].second;

        if (queries[i].type == '!'){
            v.push_back(queries[i].second);
        }
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    auto get_id = [&](ll x){
        return (int)(lower_bound(all(v), x) - v.begin()) + 1;
    };
    int m = sz(v);
    SegmentTree seg(m);
    for (int i = 0; i < n; ++i){
        seg.update(get_id(p[i]), 1);
    }
    for (int i = 0; i < q; ++i){
        if (queries[i].type == '!'){
            int k = (int)queries[i].first - 1;
            ll x = queries[i].second;
            seg.update(get_id(p[k]), -1);
            p[k] = x;
            seg.update(get_id(p[k]), 1);
        } else {
            ll a = queries[i].first;
            ll b = queries[i].second;
            int l = get_id(a);
            int r = get_id(b);
            if (v[r - 1] > b) r--;
            cout << seg.query(l, r) << endl;
        }
    }

    return 0;
}
