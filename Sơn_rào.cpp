#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MOD = (int)1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> f(n + 1);
    for (int i = 0; i <= k; ++i)
        f[i] = i + 1;
    for (int i = k + 1; i <= n; ++i)
        f[i] = (f[i - 1] + f[i - k]) % MOD;
    cout << f[n];
}
