#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    ll l, r; cin >> l >> r;
    auto sumd = [](ll n) -> ll {
        if (n <= 0){
            return 0;
        }
        ll sum = 0;
        for (ll k = 1; k <= n;){
            ll x = n / k;
            ll r = n / x;
            sum += (r - k + 1) * x;
            // cerr << "x : " << x << endl;
            // cerr << "r : " << r << endl;
            // cerr << "(r - k + 1) * x : " << (r - k + 1) * x << endl;
            k = r + 1; 
        }
        return sum;
    };
    cout << sumd(r) - sumd(l - 1);
}