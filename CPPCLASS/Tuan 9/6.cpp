#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    ll ans = 0;
    auto solve = [&](auto &&self, int l, int r){
        if (l >= r){
            return;
        }
        int mid = (l + r) / 2;
        self(self, l, mid);
        self(self, mid + 1, r);
        int szL = mid - l + 1;
        vector<int> L_max;
        vector<int> L_min;
        L_max.reserve(szL); L_min.reserve(szL);
        int mx = -INF;
        int mn = INF;
        for (int i = mid; i >= l; --i){
            mx = max(mx, a[i]);
            L_max.push_back(mx);
            mn = min(mn, a[i]);
            L_min.push_back(mn);
        }
        int szR = r - mid;
        vector<int> R_max;
        vector<int> R_min;
        R_max.reserve(szR); R_min.reserve(szR);
        mx = -INF;
        mn = INF;
        for (int i = mid + 1; i <= r; ++i){
            mx = max(mx, a[i]);
            R_max.push_back(mx);
            mn = min(mn, a[i]);
            R_min.push_back(mn);
        }
        vector<ll> pref_min(szR), pref_max(szR);
        pref_min[0] = R_min[0];
        pref_max[0] = R_max[0];
        for (int i = 1; i < szR; ++i){
            pref_max[i] = pref_max[i - 1] + R_max[i];
            pref_min[i] = pref_min[i - 1] + R_min[i];
        }
        int j1 = 0, j2 = 0;
        for (int i = 0; i < szL; ++i){
            while (j1 < szR && R_max[j1] <= L_max[i]) j1++;
            ans += 1LL * j1 * L_max[i];
            ans += pref_max[szR - 1] - (j1 > 0 ? pref_max[j1 - 1] : 0);
            while (j2 < szR && R_min[j2] >= L_min[i]) j2++;
            ans -= 1LL * j2 * L_min[i];
            ans -= pref_min[szR - 1] - (j2 > 0 ? pref_min[j2 - 1] : 0);
        }
        return;
    };
    solve(solve, 0, n - 1);
    cout << ans << endl;
    return 0;
}