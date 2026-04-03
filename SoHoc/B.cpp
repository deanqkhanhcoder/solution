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
    freopen("MULT.inp", "r", stdin);
    freopen("MULT.out", "w", stdout);
    int k; cin >> k;
    while (k--){
        ll n, x; cin >> n >> x;
        ll ans = x / n;
        cout << ans << endl;
    }
    return 0;
}