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
    vector<int> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 5, 0) {}
    void build(int id, int l, int r){
        if (l == r){
            tree[id] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
    void update(int id, int l, int r, int pos, int val){
        if (l == r){
            tree[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * id, l, mid, pos, val);
        else update(2 * id + 1, mid + 1, r, pos, val);
        tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
    int find_nth(int id, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (tree[2 * id] >= k) {
            return find_nth(2 * id, l, mid, k);
        }
        return find_nth(2 * id + 1, mid + 1, r, k - tree[2 * id]);
    }
    void build(){
        build(1, 1, n);
    }
    void update(int pos, int val){
        update(1, 1, n, pos, val);
    }
    int find_nth(int k){
        return find_nth(1, 1, n, k);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SegmentTree st(n);
    st.build();
    for (int i = 0; i < n; ++i){
        int p; cin >> p;
        int pos = st.find_nth(p);
        cout << a[pos] << ' ';
        st.update(pos, 0);
    }
    return 0;
}