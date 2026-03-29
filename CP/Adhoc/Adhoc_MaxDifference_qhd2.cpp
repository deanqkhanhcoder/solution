#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int minf = a[0];
    int ans = INT_MIN;
    for (int j = 1; j < n; j++) {
        ans = max(ans, a[j] - minf);
        minf = min(minf, a[j]);
    }
    
    cout << ans << endl;
    return 0;
}