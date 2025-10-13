#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n), pref(n);

    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    cout << "Prefix sum: ";
    for (int i = 0; i <= n; ++i) cout << pref[i] << ' ';
    cout << '\n';
}
