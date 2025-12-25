// #pragma GCC optimize("Ofast") 
// #pragma GCC optimize("unroll-loops") 
// #pragma GCC optimize("inline") 
// #include <iostream> 
// #include <vector> 
// #include <queue>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n; cin >> n;
//     vector<vector<int>> adj(1000001);
//     int limit = 0;

//     for (int i = 0; i < n; i++) {
//         int a, b; cin >> a >> b;
//         adj[a].push_back(b);
//         limit = max(limit, b);
//     }
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int ans = 0;
//     for (int day = 1; day <= limit; day++) {
//         while (!pq.empty() && pq.top() < day)
//             pq.pop();
//         for (int b : adj[day]) {
//             pq.push(b);
//         }
//         if (!pq.empty()) {
//             pq.pop();
//             ans++;
//         }
//     }
//     cout << ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long long,long long>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;

    sort(a.begin(), a.end());

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long day = 0;
    int i = 0, ans = 0;

    while (i < n || !pq.empty()) {
        if (pq.empty()) {
            day = a[i].first;
            pq.push(a[i].second);
            i++; 
        }

        while (i < n && a[i].first == day) {
            pq.push(a[i].second);
            i++;
        }

        while (!pq.empty() && pq.top() < day)
            pq.pop();

        if (!pq.empty()) {
            pq.pop(); // ăn nem
            ans++;
            day++;
        }
    }

    cout << ans;
    return 0;
}
