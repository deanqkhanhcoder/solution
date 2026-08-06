#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int a, b, x; cin >> a >> b >> x;
    ll ans = 0;
    for (int r = 0; r < x; ++r){
        ll contibution_u = (a > r ? (a - r) / x + 1 : 0);
        int need = (x - r) % x;
        ll contibution_v = (b > need ? (b - need) / x + 1 : 0);
        ans += contibution_u * contibution_v;
    }
    cout << ans << endl;
    return 0;
}