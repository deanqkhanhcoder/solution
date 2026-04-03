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
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    ll n, k; cin >> n >> k;
    ll cnt = 0;
    while (true){
        if (k & 1){
            ll half = n / 2;
            cnt += half;
            n -= half;
            k = (k + 1) / 2;
        } else {
            cout << cnt + (k / 2);
            return 0;
        }
    }
}