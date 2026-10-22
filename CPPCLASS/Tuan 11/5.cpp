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

struct SegmentTreeMax {
    int n;
    vector<int> tree;
    SegmentTreeMax(int n) : n(n), tree(4 * n + 5, 0) {}
    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            tree[id] = a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }
    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            tree[id] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * id, l, mid, pos, val);
        else update(2 * id + 1, mid + 1, r, pos, val);
        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }
    int query(int id, int l, int r, int x) {
        if (tree[id] < x) return 0;
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (tree[2 * id] >= x) return query(2 * id, l, mid, x);
        else return query(2 * id + 1, mid + 1, r, x);
    }
    void build(vector<int> &a){
        build(a, 1, 1, n);
    }
    void update(int pos, int val){
        update(1, 1, n, pos, val);
    }
    int query(int x){
        return query(1, 1, n, x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    SegmentTreeMax st(n);
    st.build(a);
    for (int i = 0; i < m; ++i){
        int pos = st.query(b[i]);
        if (pos != 0) st.update(pos, -b[i]);
        cout << pos << ' ';
    }
    cout << endl;
    return 0;
}