#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int ds(int x) {
    int s = 0;
    while (x > 0) { 
        s += x % 10; 
        x /= 10; 
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h; cin >> n >> h;
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for (int i = 4; i <= n; i += 2)
        p[i] = false;
    for (int i = 3; i * i <= n; i += 2) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                p[j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 2; i <= n; ++i) {
        if (p[i] && ds(i) == h) ans.push_back(i);
    }
    for (int x : ans) cout << x << '\n';
    cout << ans.size();
    return 0;
}
