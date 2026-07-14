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
    vector<int> a(n);
    for (int &e : a) cin >> e;
    int half = n / 2;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < half; ++i){
        int curr = i * 2;
        int next = curr + 1;
        pq.push(a[curr]);
        pq.push(a[next]);
        pq.pop();
    }
    ll ans = 0;
    while (!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}