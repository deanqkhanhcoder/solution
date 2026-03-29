#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (ll k = 1; k <= n; ++k) {
        ll sqr = k * k;
        ll res = sqr * (sqr - 1) / 2;
        if (k > 2) res -= 4 * (k - 1) * (k - 2);
        cout << res << '\n';
    }
    return 0;
}
