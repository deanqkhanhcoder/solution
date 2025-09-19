#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (a[i] <= b[j]) cout << a[i++] << " ";
        else cout << b[j++] << " ";
    }
    while (i < n) cout << a[i++] << " ";
    while (j < n) cout << b[j++] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
