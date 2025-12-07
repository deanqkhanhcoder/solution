#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; int k;
    cin >> n >> k;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0){
                --k;
                n /= i;
                if (k == 0){
                    cout << i;
                    return 0;
                }
            }
        }
    }
    if (n > 1) {
        if (k == 1){
            cout << n;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
