#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    ll t = 0;
    for (int &x : a){
        cin >> x;
        t += x;
    }
    ll ans = LLONG_MIN, p = 0;
    for (int i = 0; i < n; i++) {
        p += a[i];
        ans = max(ans, abs(2 * p - t));
    }
    cout << ans;
    return 0;
}
