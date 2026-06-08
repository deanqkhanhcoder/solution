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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        vector<int> max_pref(n);
        vector<int> max_suff(n);
        max_pref[0] = a[0];
        for (int i = 1; i < n - 2; ++i){
            max_pref[i] = max(max_pref[i - 1], a[i] + i);
        }
        max_suff[n - 1] = a[n - 1] - (n - 1);
        for (int i = n - 2; i >= 2; --i){
            max_suff[i] = max(max_suff[i + 1], a[i] - i);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i){
            int maxL = max_pref[i - 1];
            int maxR = max_suff[i + 1];
            ans = max(ans, maxL + maxR + a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}