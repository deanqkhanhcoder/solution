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
    ll sum, pref, suff, best;
    Node (ll x = 0){
        sum = x;
        pref = suff = best = max(0LL, x);
    }
    Node(ll sum, ll pref, ll suff, ll best) : sum(sum), pref(pref), suff(suff), best(best) {}
};
Node merge(Node L, Node R){
    ll sum = L.sum + R.sum;
    ll pref = max(L.pref, L.sum + R.pref);
    ll suff = max(R.suff, R.sum + L.suff);
    ll best = max({L.best, R.best, L.suff + R.pref});
    return {sum, pref, suff, best};
};
struct SegmentTree{
    int n;
    vector<Node> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5) {}
    void build(vector<int> &a, int id, int l, int r){
        if (l == r){
            tree[id] = Node(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }
    void update(int id, int l, int r, int pos, ll val){
        if (l == r){
            tree[id] = Node(val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * id, l, mid, pos, val);
        else update(2 * id + 1, mid + 1, r, pos, val);
        tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
    }
    void build(vector<int> &a){
        build(a, 1, 1, n);
    }
    void update(int pos, ll val) {
        update(1, 1, n, pos, val);
    }
    ll query() {
        return tree[1].best;
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
    for (int i = 0; i < q; ++i){
        int k; ll x; cin >> k >> x;
        st.update(k, x);
        cout << st.query() << endl;
    }
    return 0;
}