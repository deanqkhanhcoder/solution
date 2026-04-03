#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int m, Q; cin >> m >> Q;
    vector<int> cost(m + 1);
    cost[0] = 0;
    for (int i = 1; i <= m; ++i) cin >> cost[i];
    sort(all(cost));
    vector<ll> pref(m + 1);
    pref[0] = 0;
    for (int i = 1; i <= m; ++i){
        pref[i] = pref[i - 1] + cost[i];
    }
    while (Q--){
        ll n; cin >> n;
        auto it = upper_bound(all(pref), n);
        if (it == pref.begin()){
            cout << "0 0" << endl;
            continue;
        }
        it--;
        int len = it - pref.begin();
        int minest = cost[1];
        int l = len, r = m;
        // cerr << "l : " << l << endl;
        if (l > r){
            cout << len << " " << minest << endl;
            continue;
        }
        while (l < r){
            int mid = (l + r + 1) / 2;
            // cerr << "mid : " << mid << " l: " << l << " r: " << r << endl;
            ll sum = pref[mid] - pref[mid - len];
            if (sum <= n) l = mid;
            else r = mid - 1;
        }
        minest = cost[l - len + 1];
        cout << len << " " << minest << endl;
    }
    return 0;
}