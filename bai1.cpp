#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("inline")
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    freopen("HEIGHT.INP", "r", stdin);
    freopen("HEIGHT.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, h;
    cin >> a >> b >> h;

    double rad = b * M_PI / 180.0;
    double ans = a * tan(rad) + h;

    cout << fixed << setprecision(3) << ans;
}
