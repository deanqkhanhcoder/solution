#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> MOD(n, 0);
    MOD[0] = 1;
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        int mod = (sum % n + n) % n;
        ans += MOD[mod];
        MOD[mod]++;
    }
    cout << ans;
    return 0;
}