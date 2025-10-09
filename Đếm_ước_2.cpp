#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> s(int n) {
    vector<int> pr;
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for (int i = 4; i <= n; i += 2) p[i] = false;
    for (int i = 3; i * i <= n; i += 2) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += 2 * i)
                p[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (p[i]) pr.push_back(i);
    return pr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> pr = s(31623);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        ll ans = 1;
        for (int p : pr) {
            if (1LL * p * p > x) break;
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ans *= (cnt + 1);
            }
        }
        if (x > 1) ans *= 2;
        cout << ans << '\n';
    }
    return 0;
}
