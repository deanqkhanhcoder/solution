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
        if (l == r){
            ans += a[l];
            return;
        }
        int mid = (l + r) / 2;
        self(self, l, mid);
        self(self, mid + 1, r);
        vector<int> L;
        L.reserve(mid - l + 1);
        int mx = 0;
        for (int i = mid; i >= l; --i) {
            mx = max(mx, a[i]);
            L.push_back(mx);
        }
        vector<int> R;
        R.reserve(r - mid);
        mx = 0;
        for (int i = mid + 1; i <= r; ++i){
            mx = max(mx, a[i]);
            R.push_back(mx);
        }
        vector<ll> pref(r - mid);
        pref[0] = R[0];
        for (int i = 1; i < r - mid; ++i){
            pref[i] = pref[i - 1] + R[i];
        }
        int i = 0;
        for (int x : L){
            while (i < r - mid && R[i] <= x) i++;
            ans += 1LL * x * i;
            ans += pref[r - mid - 1] - (i == 0 ? 0 : pref[i - 1]);
        }
        return;
    };
    // cout << "ok" << endl;
    solve(solve, 0, n - 1);
    cout << ans << endl;
    return 0;
}