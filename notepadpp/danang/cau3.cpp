#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<double> pref;
int n, k;

bool check(double x) {
    vector<double> p(n + 1, 0.0);
    for (int i = 1; i <= n; i++) {
        p[i] = pref[i] - x * i;
    }

    double test = 0.0;
    for (int j = k; j <= n; j++) {
        test = min(test, p[j - k]);
        if (p[j] - test >= 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<double> a(n);
    double hi = 1e9;
    double lo = 0.0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        hi = max(hi, a[i]);
        lo = min(lo, a[i]);
    }

    pref.assign(n + 1, 0.0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    double ans = 0;

    while (hi - lo > 1e-3) {
        double mid = (lo + hi) / 2.0;
        if (check(mid)) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(3) << ans << "\n";
}