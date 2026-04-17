#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
struct solve {
    ll l, r;
    solve(ll l, ll r){
        this->l = l - 1;
        this->l = max(this->l, 0LL);
        this->r = r;

    }
    int cnt(){
        int root1 = sqrtl(r);
        int root2 = sqrt(l);
        return root1 - root2;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    ll p, q, n; cin >> p >> q >> n;
    solve ans(p, q);
    cout << ans.cnt();
    return 0;
}
