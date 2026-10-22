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
    int n;
    ll S;
    cin >> n >> S;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll sum = 0;
    int l = 0, ans = INF;
    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (sum >= S) {
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}