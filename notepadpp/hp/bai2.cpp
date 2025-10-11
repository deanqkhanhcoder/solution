#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, m; cin >> a >> b >> m;
    int ans = 0;
    for (int x = 0; x * a <= m; ++x) {
        int y = (m - a * x) / b;
        ans = max(ans, a * x + b * y);
    }
    cout << ans << "\n";
    return 0;
}