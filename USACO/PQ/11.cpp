#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
struct type{
    int l, r, t;
    bool operator<(const type &o) const {
        return r < o.r;
    }
};
struct Fenwick{
    int n;
    vector<int> BIT;
    Fenwick(int n) : n(n), BIT(n + 1, 0) {}
    void add(int i, int val){
        for (; i <= n; i += i & -i){
            BIT[i] += val;
        }
        return;
    }
    int query(int i){
        int ans = 0;
        for (; i > 0; i -= i & -i){
            ans += BIT[i];
        }
        return ans;
    }
    int get(int l, int r){
        return query(r) - query(l - 1);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        sort(all(a));
        vector<type> b;
        for (int i = 0; i < k; ++i){
            int l, r, t; cin >> l >> r >> t;
            int L = lower_bound(all(a), l) - a.begin() + 1;
            int R = upper_bound(all(a), r) - a.begin();
            if (L <= R && t > 0){
                b.push_back({L, R, t});
            } 
        }
        sort(all(b));
        Fenwick ft(n);
        set<int> alive;
        for (int i = 1; i <= n; ++i) alive.insert(i);
        int ans = 0;
        for (type &q : b){
            int L = q.l;
            int R = q.r;
            int t = q.t;
            int curr = ft.get(L, R);
            if (curr < t){
                int need = t - curr;
                while (need > 0){
                    auto it = alive.upper_bound(R);
                    it--;
                    ft.add(*it, 1);
                    alive.erase(it);
                    need--;
                    ans++;
                }
            }
        }
        cout << n - ans << endl;
    }
    return 0;
}