#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 1; i <= n;) {
        ll q = n / i;        // giá trị n / i
        ll j = n / q;        // i..j đều có n/k = q
        // tổng từ i đến j: (i + j) * (j - i + 1) / 2
        ll sum_ij = (i + j) % MOD * ((j - i + 1) % MOD) % MOD * ((MOD + 1) / 2) % MOD;
        ans = (ans + sum_ij * (q % MOD)) % MOD;
        i = j + 1;
    }

    cout << ans << "\n";
    return 0;
}
