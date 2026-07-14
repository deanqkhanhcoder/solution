#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        int maxest = a[0];
        int dist = 0;
        for (int i = 1; i < n; ++i){
            if (a[i] < maxest){
                dist = max(dist, maxest - a[i]);
            }
            maxest = max(maxest, a[i]);
        }
        /*
        2^t - 1 >= dist
        => 2^t >= dist + 1
        >= 2^t > dist
        => T = (d_max == 0) ? 0 : (64 - __builtin_clzll(d_max));
        */
        if (dist == 0){
            cout << 0 << endl;
        } else {
            int t = 64 - __builtin_clzll(dist);
            cout << t << endl;
        }
    }
    return 0;
}