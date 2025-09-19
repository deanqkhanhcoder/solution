#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    int lm[n];
    int rm[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lm[0] = INT_MIN;
    for (int i = 1; i < n; i++) {
        lm[i] = max(lm[i-1], a[i-1]);
    }
    rm[n-1] = INT_MAX;
    for (int i = n-2; i > 0; i--) {
        rm[i] = min(rm[i+1], a[i+1]);
    }
    int ans = INT_MIN;
    for (int j = 1; j < n-1; j++) {
        ans = max(ans, lm[j] + a[j] - rm[j]);
    }
    cout << ans << "\n";
    return 0;
}