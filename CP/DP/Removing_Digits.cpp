#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
int maxd(int x) {
    if (x < 10) return x;
    int res = 0;
    while (x) {
        int d = x % 10;
        if (d == 9) return 9;
        res = max(res, d);
        x /= 10;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    while (n > 0) {
        n -= maxd(n);
        ans++;
    }
    cout << ans;
}