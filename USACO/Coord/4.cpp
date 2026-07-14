#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
struct event{
    int x, idx;
    bool type;
    bool operator<(const event &o) const{
        return x < o.x;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "lifeguards"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    vector<event> a;
    for (int i = 0; i < n; ++i){
        int l, r; cin >> l >> r;
        a.push_back({l, i, true});
        a.push_back({r, i, false});
    }
    sort(all(a));
    set<int> alive;
    vector<ll> alone(n, 0);
    int prev = 0;
    ll total = 0;
    for (int i = 0; i < 2 * n; ++i){
        int curr = a[i].x;
        int len = curr - prev;
        if (!alive.empty()){
            total += len;
        }
        if ((int)alive.size() == 1){
            alone[*alive.begin()] += len;
        }
        if (a[i].type){
            alive.insert(a[i].idx);
        } else {
            alive.erase(a[i].idx);
        }
        prev = curr;
    }
    ll min_alone = *min_element(all(alone));
    cout << total - min_alone << endl;
}