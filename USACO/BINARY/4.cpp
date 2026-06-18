#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "cowdance"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    auto check = [&](int k) -> bool {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i){
            if ((int)pq.size() < k){
                pq.push(a[i]);
            } else {
                int curr = a[i] + pq.top();
                if (curr > t) return false;
                pq.pop();
                pq.push(curr);
            }
        }
        return true;
    };  
    int lo = 1, hi = n;
    while (lo < hi){
        int mid = (hi + lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
    return 0;
}