#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "DCS"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, S; cin >> n >> S;   
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i){
        int a; cin >> a;
        pref[i] = pref[i - 1] + a;
    }
    vector<int> minsuf(n + 1);
    minsuf[n] = pref[n];
    for (int i = n - 1; i > 0; --i){
        minsuf[i] = min(minsuf[i + 1], pref[i]);
    }
    // for (int i = 1; i <= n; ++i){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; ++i){
    //     cout << minsuf[i] << " ";
    // }
    int x = 0, y = -1;
    for (int i = 0; i < n; ++i){
        int target = S + pref[i];
        auto it = upper_bound(minsuf.begin() + i + 1, minsuf.end(), target);
        if (it == minsuf.begin() + i + 1) continue;
        int len = it - minsuf.begin() - (i + 1);
        if (len > x){
            x = len;
            // if (x == 5) cout << "i : " << i << endl;
            y = i + 1;
        }
    }
    cout << x << " " << y;
    return 0;
}