#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
vector<int> f(1e6 + 1, 0);
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (f[i] == 0) {
            for (int j = i; j <= n; j += i) {
                if (f[j] == 0) f[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e6);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        vector<int> res;
        int last = -1;
        while (x > 1) {
            int p = f[x];
            if (p != last) res.push_back(p);
            last = p;
            while (x % p == 0) x /= p;
        }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 == res.size() ? '\n' : ' ');
    }
    return 0;
}
