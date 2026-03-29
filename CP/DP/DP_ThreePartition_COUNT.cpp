#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0){
        cout << 0;
        return 0;
    }
    ll need = sum / 3;
    ll cur = 0;
    ll cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i){
        cur += a[i];
        if (cur == need * 2){
            ans += cnt;
        }
        if (cur == need){
            cnt++;
        }
    }
    cout << ans;
    return 0;
}