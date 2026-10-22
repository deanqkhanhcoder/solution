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
    int cur = 0;
    int ans = -INF;
    for (int x : a) {
        cur = max(cur + x, x);
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}