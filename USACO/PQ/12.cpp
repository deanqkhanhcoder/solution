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
    // code here
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<pair<ll, ll>> a(n);
        for (pair<ll, ll> &p : a){
            cin >> p.first >> p.second;
            p.first += p.second;
        }
        sort(all(a));
        ll sum = 0;
        priority_queue<ll> pq;
        for (auto [d, t] : a){
            pq.push(t);
            sum += t;
            if (sum > d){
                sum -= pq.top();
                pq.pop();
            }
        }
        cout << sz(pq) << endl;
    }
    return 0;
}