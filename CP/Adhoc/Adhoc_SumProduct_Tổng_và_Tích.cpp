#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <unordered_map>
#include <cmath>
#define endl "\n"
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    unordered_map<ll, ll> cnt;
    cnt.reserve(2 * n);
    cnt.max_load_factor(0.7);
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        cnt[a]++;
    }
    int q; cin >> q;
    while(q--){
        ll b, c; cin >> b >> c;    
        ll delta = b*b - 4*c;
        if (delta < 0){
            cout << "0" << endl;
            continue;
        }
        if (delta == 0){ 
            if (b % 2 != 0) {
                cout << 0 << endl;
                continue;
            } 
            int k = cnt[b / 2];
            cout << (ll)k * (k - 1) / 2 << endl;
            continue;
        }
        ll s = sqrtl(delta);
        if (s * s != delta) {
            cout << 0 << '\n';
            continue;
        }
        ll x = b - s;
        if (x % 2 != 0){
            cout << 0 << '\n';
            continue;
        }
        x >>= 1;
        ll y = (b + s)/2;
        cout << cnt[x] * cnt[y] << endl;
    }
    return 0;
}