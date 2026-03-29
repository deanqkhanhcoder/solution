#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n; vector<ll> bit; 
void update(int i, ll x){
    while (i <= n){
        bit[i] = max(bit[i], x);
        i += i & -i;
    }
}
ll query (int i){
    ll ans = 0;
    while (i > 0){
        ans = max(ans, bit[i]);
        i -= i & -i;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> h(n);
    vector<int> a(n);
    for (int &e : h) cin >> e;
    for (int &e : a) cin >> e;
    bit.assign(n + 1, 0);
    for (int i = 0; i < n; ++i){
        ll best = query(h[i] - 1);
        update(h[i], best + a[i]);
    }
    cout << query(n);
    return 0;
}