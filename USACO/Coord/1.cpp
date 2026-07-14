#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

struct seg {
    int l, r, val;
    seg() {}
};
struct qr {
    int l, r;
    qr() {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<seg> a(n);
    vector<int> point;
    for (seg &e : a){
        cin >> e.l >> e.r >> e.val;
        point.push_back(e.l);
        point.push_back(e.r);
    }
    vector<qr> b(q);
    for (qr &e : b){
        cin >> e.l >> e.r;
        point.push_back(e.l);
        point.push_back(e.r);
    }
    sort(all(point));
    point.erase(unique(all(point)), point.end());
    int m = (int)point.size();
    auto get = [&](int x) -> int {
        return lower_bound(all(point), x) - point.begin();
    };
    vector<int> diff(m, 0);
    for (int i = 0; i < n; ++i){
        int l = get(a[i].l);
        int r = get(a[i].r);
        diff[l] += a[i].val;
        diff[r] -= a[i].val;
    }
    vector<ll> pref(m);
    pref[0] = 0;
    ll val = 0;
    for (int i = 1; i <= m - 1; ++i){
        int range = point[i] - point[i - 1];
        val += diff[i - 1];
        pref[i] = pref[i - 1] + 1LL * val * range;
    }
    for (int i = 0; i < q; ++i){
        int l = get(b[i].l);
        int r = get(b[i].r);
        cout << pref[r] - pref[l] << endl;
    }
    return 0;
}   