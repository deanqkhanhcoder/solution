#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
struct interval{
    int l, time, idx;
    bool operator<(const interval &o) const{
        return l < o.l;
    }
};
struct cmp {
    bool operator()(const interval &a, const interval &b) const {
        return a.idx > b.idx;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n; cin >> n;
    vector<interval> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i){
        int l, time; cin >> l >> time;
        a.push_back({l, time, i});
    }
    sort(all(a));
    priority_queue<interval, vector<interval>, cmp> pq;
    int time = 0;
    int ans = 0;
    int i = 0;
    while (i < n || !pq.empty()){
        if (i < n && a[i].l <= time){
            pq.push(a[i]);
            i++;
        } else if (pq.empty()){
            time = a[i].l + a[i].time;
            i++;
        } else {
            interval low = pq.top();
            ans = max(ans, time - low.l);
            time += low.time;
            pq.pop();
        }
    }
    cout << ans << endl;
}