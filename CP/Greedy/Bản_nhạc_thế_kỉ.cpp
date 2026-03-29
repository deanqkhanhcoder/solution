#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<ll> b(n);
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        b[i] = a - 1LL*i*k;
    }
    sort(b.begin(), b.end());
    ll mid = llabs(b[n / 2]);
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        ans += llabs(b[i] - mid);
    }
    cout << ans;
    return 0;
}