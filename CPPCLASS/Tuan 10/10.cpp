#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int n, d; cin >> n >> d;
    // code here    
    // vector<pair<int, int>> a(n);
    // for (auto &x : a) cin >> x.first >> x.second;
    // sort(all(a));
    // vector<pair<int, int>> segments;
    // int curL = a[0].first;
    // int maxR = a[0].second;
    // for (int i = 1; i < n; ++i){
        //     if (a[i].first <= maxR){
            //         maxR = max(maxR, a[i].second);
            //     } else {
                //         segments.push_back({curL, maxR});
                //         curL = a[i].first;
                //         maxR = a[i].second;
                //     }
                // }
                // segments.push_back({curL, maxR});
                // int m = sz(segments);
                // int ans = m;
    // for (int i = 1; i < m; i++){
    //     if (segments[i].first - segments[i - 1].second <= d) ans--;
    // }
    // cout << ans << endl;
    int n, d; cin >> n >> d;
    const int M = INF - d + 1;
    vector<pair<int, int>> a(n);
    for (auto &p : a) {
        int L, R;
        cin >> L >> R;
        p.first = min(R, M);
        p.second = L - d + 1;
    }
    sort(all(a));
    int last = -INF;
    int ans = 0;
    for (auto [r, l] : a){
        if (last < l){
            last = r;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}