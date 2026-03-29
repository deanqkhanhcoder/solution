#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for (auto &e : a) cin >> e.first >> e.second;
    sort(a.begin(), a.end());
    priority_queue<int> pq;
    ll cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        pq.push(a[i].second);
        cur += a[i].second;
        while (!pq.empty() && cur + a[i].first > m) {
            cur -= pq.top();
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
    return 0;
}
