#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
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
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int &e : a){
            cin >> e;
            e %= m;
        }
        sort(all(a));
        vector<int> b(2 * n + 1);
        for (int i = 1; i <= n; ++i){
            b[i] = a[i - 1];
            b[i + n] = b[i] + m;
        }
        vector<ll> pref(2 * n + 1);
        pref[0] = 0;
        for (int i = 1; i <= 2 * n; ++i){
            pref[i] = pref[i - 1] + b[i];
        }
        auto get_sum = [&](int l, int r) -> ll{
            if (l > r) return 0;
            return pref[r] - pref[l - 1];
        };
        ll ans = LLONG_MAX;
        for (int l = 1; l <= n + 1; ++l){
            int r = l + n - 1;
            int mid = (l + r) / 2;
            int cnt_left = mid - l;
            int cnt_right = r - mid;
            ll total_left = 1LL * cnt_left * b[mid] - get_sum(l, mid - 1);
            ll total_right = get_sum(mid + 1, r) - 1LL * cnt_right * b[mid];
            ans = min(ans, total_left + total_right);
        }
        cout << ans << endl;
    }
    return 0;
}