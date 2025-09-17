#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), [](auto &x, auto &y) { return x.first.first < y.first.first; });
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> ans(n);
    int rcnt = 0;
    for (auto &g : v) {
        int a = g.first.first, b = g.first.second, idx = g.second;
        if (!pq.empty() && pq.top().first < a) {
            auto room = pq.top().second;
            pq.pop();
            ans[idx] = room;
            pq.push({b, room});
        } else {
            rcnt++;
            ans[idx] = rcnt;
            pq.push({b, rcnt});
        }
    }
    cout << rcnt << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
