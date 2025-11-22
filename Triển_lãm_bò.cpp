#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
constexpr int INF = (int)-1e9;
constexpr int SHIFT = 100 * 5000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a;
    vector<int> b;
    a.reserve(n);
    b.reserve(n);
    for (int i = 0; i < n; ++i){
        int ai; cin >> ai;
        int bi; cin >> bi;
        if (ai < 0 && bi < 0) continue;
        a.push_back(ai);
        b.push_back(bi);
    }
    n = (int)a.size();
    const int MAXIQ = SHIFT * 2;
    vector<int> dp(MAXIQ + 1, INF);
    dp[SHIFT] = 0;
    int l = SHIFT, r = SHIFT;
    for (int i = 0; i < n; ++i){
        vector<int> pre = dp;
        int ai = a[i];
        int bi = b[i];
        for (int iq = l; iq <= r; ++iq){
            if (pre[iq] == INF) continue;
            int niq = iq + ai;
            if (niq < 0 || niq > MAXIQ) continue;
            dp[niq] = max(dp[niq], pre[iq] + bi);
        }
        int nl = l + ai;
        int nr = r + ai;
        l = max(0, min(l, nl));
        r = min(MAXIQ, max(r, nr));
    }
    int ans = 0;
    for (int iq = SHIFT; iq <= MAXIQ; iq++) {
        if (dp[iq] >= 0) {
            int ans1 = iq - SHIFT;
            int ans2 = dp[iq];
            ans = max(ans, ans1 + ans2);
        }
    }
    cout << ans;
    return 0;
}
