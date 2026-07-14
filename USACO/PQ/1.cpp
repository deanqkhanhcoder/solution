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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    int idx = 0;
    for (auto &p : a){
        cin >> p.first.first >> p.first.second;
        p.second = idx++; 
    }
    sort(all(a));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int room = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i){
        int l = a[i].first.first;
        int r = a[i].first.second;
        idx = a[i].second;
        if (!pq.empty() && pq.top().first < l){
            ans[idx] = pq.top().second;
            pq.pop();
            pq.push({r, ans[idx]});
        } else {
            room++;
            ans[idx] = room;
            pq.push({r, room});
        }
    }
    cout << room << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    return 0;
}