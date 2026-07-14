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
    int x, n; cin >> x >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        pq.push(a);
    }
    ll ans = 0;
    while (sz(pq) > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        int s_min = min1 + min2;
        pq.push(s_min);
        ans += s_min;
    }
    cout << ans << endl;
    return 0;
}