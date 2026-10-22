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
        int szL = mid - l + 1;
        vector<int> L;
        L.reserve(szL);
        int mx = 0;
        for (int i = mid; i >= l; --i) {
            mx = max(mx, a[i]);
            L.push_back(mx);
        }
        int szR = r - mid;
        vector<int> R;
        R.reserve(szR);
        mx = 0;
        for (int i = mid + 1; i <= r; ++i){
            mx = max(mx, a[i]);
            R.push_back(mx);
        }
        vector<ll> pref_s(szR), pref_w(szR);
        pref_s[0] = R[0];
        pref_w[0] = R[0];
        for (int i = 1; i < r - mid; ++i){
            pref_s[i] = pref_s[i - 1] + R[i];
            pref_w[i] = pref_w[i - 1] + 1LL * R[i] * (i + 1);
        }
        int j = 0;
        for (int i = 0; i < szL; ++i){
            int x = L[i];
            while(j < szR && R[j] <= x) ++j;
            ll len_s = 1LL * (i + 1) * j + 1LL * j * (j + 1) / 2;
            ans += 1LL * x * len_s;
            if (j < szR){
                ll sr = 1LL * (i + 1) * (pref_s[szR - 1] - (j > 0 ? pref_s[j - 1] : 0));
                ll sw = pref_w[szR - 1] - (j > 0 ? pref_w[j - 1] : 0);
                ans += sr + sw;
            }
        }
        return;
    };
    // cout << "ok" << endl;
    solve(solve, 0, n - 1);
    cout << ans << endl;
    return 0;
}