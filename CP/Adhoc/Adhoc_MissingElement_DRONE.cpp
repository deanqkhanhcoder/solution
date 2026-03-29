#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L; cin >> n >> L;
    int R = L + n - 1;
    ll sum = (L + R + 0LL) * n / 2;
    ll cur = 0;
    for (int i = 1; i < n; ++i){
        int a; cin >> a;
        cur += a;
    }
    cout << sum - cur;
}