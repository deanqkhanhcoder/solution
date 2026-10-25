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
struct FenwickTree{
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1) {}
    void add(int i, int val) {
        for (; i <= n; i += lowbit(i))
            tree[i] += val;
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i))
            res += tree[i];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here   
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> v;
    for (int &x : a) {
        cin >> x;
        v.push_back(x);
    }
    vector<pair<char, pair<int, int>>> queries(q);
    for (auto &p : queries) {
        cin >> p.first >> p.second.first >> p.second.second;
        if (p.first == '!') v.push_back(p.second.second);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    auto getID = [&](int x) {
        return lower_bound(all(v), x) - v.begin() + 1;
    };
    int m = sz(v);
    FenwickTree ft(m);
    for (int x : a) ft.add(getID(x), 1);
    for (int i = 0; i < q; ++i){
        char type = queries[i].first;
        if (type == '!'){
            int k = queries[i].second.first;
            int x = queries[i].second.second;
            k--;
            ft.add(getID(a[k]), -1);
            a[k] = x;
            ft.add(getID(a[k]), 1);
        } else if (type == '?'){
            int a = queries[i].second.first;
            int b = queries[i].second.second;
            int l = lower_bound(all(v), a) - v.begin() + 1;
            int r = upper_bound(all(v), b) - v.begin();
            int ans = ft.sum(r) - ft.sum(l - 1);
            cout << ans << endl;
        } 
    }
    return 0;
}