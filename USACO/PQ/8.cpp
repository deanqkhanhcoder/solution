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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    priority_queue<int, vector<int>, greater<>> pq;
    int curr = 0;
    for (int i = 0; i < n; ++i){
        int reach = min(n - 1, i + k);
        while (curr <= reach){
            pq.push(a[curr]);
            curr++;
        }
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}