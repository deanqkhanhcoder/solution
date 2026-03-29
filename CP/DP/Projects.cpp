#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
struct jc{
    int a; int b; int p;
    bool operator<(const jc& other) const {
        return b < other.b;
    }

};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<jc> a(n);
    for (auto &j : a) cin >> j.a >> j.b >> j.p;
    sort(a.begin(), a.end());
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; ++i){
        int idx = upper_bound(a.begin(), a.end(), a[i].a - 1, [](int val, const jc &x){return val < x.b;}) - a.begin();
        ll ic = (idx > 0 ? dp[idx - 1] + a[i].p : a[i].p);
        ll ex = (i > 0 ? dp[i - 1] : 0);
        dp[i] = max(ic, ex);
    }
    cout << dp[n - 1];
    return 0;
}