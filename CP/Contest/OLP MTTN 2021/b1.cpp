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
using i128 = __int128_t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    ll a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
    // if ((a1 < a2 && b1 > b2) || (a1 > a2 && b1 < b2)){
    //     cout << "NO";
    //     return 0;
    // }
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    i128 lhs = (__int128)a1 * b2;
    i128 rhs = (__int128)a2 * b1;
    cout << (lhs == rhs ? "YES" : "NO");
}