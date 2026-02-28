#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <iomanip>
using namespace std;
using ll = long long;
constexpr double EPS = 1e-9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x1, x2, v1, v2;
    cin >> x1 >> x2 >> v1 >> v2;
    if (v1 == v2 && x1 != x2){
        cout << -1;
        return 0;
    } else if (v1 == v2 && x1 == x2){
        cout << 0;
        return 0;
    }
    double ans = (double)(x1 - x2) / (v2 - v1);
    if (ans < 0){
        cout << -1;
    } else {
        cout << fixed << setprecision(4) << ans;
    }
    return 0;
}