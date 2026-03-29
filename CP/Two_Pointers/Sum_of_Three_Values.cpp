#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
using namespace std;
using uint = unsigned int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    pair<int, int> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i <= n - 3 && a[i].first <= x/3; ++i) {
        uint l = i + 1, r = n - 1;
        while (l < r) {
            uint s = a[i].first + a[l].first + a[r].first;
            if (s == x) {
                cout << a[i].second + 1 << ' ' 
                     << a[l].second + 1 << ' ' 
                     << a[r].second + 1;
                return 0;
            } else if (s < x) {
                ++l;
            } else {
                --r;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
