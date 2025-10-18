#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x; cin >> x;
    int n = x / 28;
    int ans = n;
    while (n >= 3){
        int t = n / 3;
        ans += t;
        n = t + n % 3;
    }
    cout << ans;
    return 0;
}