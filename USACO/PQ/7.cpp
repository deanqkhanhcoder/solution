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
    #define TASK "helpcross"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int c, n; cin >> c >> n;
    vector<int> a(c);
    for (int &e : a) cin >> e;
    sort(all(a));
    vector<pair<int, int>> b(n);
    for (pair<int, int> &p : b) cin >> p.first >> p.second;
    sort(all(b));
    priority_queue<int, vector<int>, greater<>> pq;
    int ans = 0;
    int i = 0;
    for (int x : a){
        while(i < n && b[i].first <= x){
            pq.push(b[i].second);
            i++;
        }
        while (!pq.empty() && pq.top() < x) pq.pop();
        if (!pq.empty()){
            pq.pop();
            ans++;
        }
    } 
    cout << ans << endl;
    return 0;
}