#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
vector<int> a;

bool check(double mid) {
    double cnt = 0;
    for (int e : a) {
        cnt += floor((1.0 * e * e) / mid);
        if (cnt >= k) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    a.resize(n);
    double hi = 0;
    for (int &e : a) {
        cin >> e;
        hi = max(hi, (double)e);
    }
    hi *= hi;
    double lo = 0;
    while (hi - lo > 1e-6) {
        double mid = (lo + hi) / 2.0;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout.setf(ios::fixed);
    cout.precision(3);
    cout << lo << '\n';
}
