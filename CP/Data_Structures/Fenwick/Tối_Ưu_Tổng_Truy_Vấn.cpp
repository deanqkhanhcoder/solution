#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define lowbit(i) ((i) & (-(i)))
using namespace std;
using ll = long long;
struct FenwickTree{
    int n;
    vector<ll> bits;
    FenwickTree(int n) : n(n), bits(n + 1, 0) {}
    FenwickTree(vector<ll> &a) : FenwickTree(a.size()) {
        for (int i = 1; i <= (int)a.size(); i++){
            bits[i] += a[i];
            int j = i + lowbit(i);
            if (j <= n) bits[j] += bits[i]; 
        }
    }
    void add(int i, int val){
        for (; i <= n; i += lowbit(i)){
            bits[i] += val;
        }
    }
    ll query(int i){
        ll res = 0;
        for (; i > 0; i -= lowbit(i)){
            res += bits[i];
        }
        return res;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    int n, q, m; cin >> n >> q >> m;
    vector<int> a(n + 1);
    a[0] = 0;
    vector<ll> diff(n + 1);
    set<int> s;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (i > 1 && a[i] != a[i - 1]){
            s.insert(i - 1);
        }
    }
    diff[0] = 0;
    for (int i = 1; i <= n; ++i){
        diff[i] = a[i] - a[i - 1];
    }
    FenwickTree ft(diff);
    auto check = [&](int i){
        return ft.query(i) % m != ft.query(i + 1) % m;
    };
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int l, r, val; cin >> l >> r >> val;
            if (val % m == 0) continue;
            ft.add(l, val);
            if (r + 1 <= n) ft.add(r + 1, -val);
            if (l > 1) {
                if (check(l - 1)) s.insert(l - 1);
                else s.erase(l - 1);
            }
            if (r < n) {
                if (check(r)) s.insert(r);
                else s.erase(r);
            }
        }
        if (type == 2){
            int l, r; cin >> l >> r;
            if (l == r){
                cout << "NO" << endl;
                continue;
            }
            auto it = s.lower_bound(l);
            cout << ((it != s.end() && *it < r) ? "YES" : "NO");
            cout << endl;
        }
    }
    return 0;
}