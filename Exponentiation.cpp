#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
const int MOD = (int) 1e9 +7;
int binbow(ll a, ll b){
    ll res = 1;
    a %= MOD;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    while (n--){
        ll a, b; cin >> a >> b;
        cout << binbow(a, b) << "\n";
    }
}
