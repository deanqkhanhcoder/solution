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
    freopen("PTB2.inp", "r", stdin);
    freopen("PTB2.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    ll ans = 0;
    if (n <= 3000){
        for (int i = n - 1; i >= 2; --i){
            int L = 0;
            int R = i - 1;
            while (L < R){
                if (a[L] + a[R] == a[i]){
                    ans += 2;
                    L++;
                    R--;
                } else if (a[L] + a[R] < a[i]) L++;
                else R--;
            } 
        }
    } else {
        for (int i = 0; i < n; ++i){
            if (a[i] % 2 == 0) ans += a[i] - 2;
            else ans += a[i] - 1;
        }
    }
    cout << ans;
}