#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SODEP.INP", "r", stdin);
    freopen("SODEP.OUT", "w", stdout);
    int n; cin >> n;
    int ans = 0;
    while (n > 0){
        ans += n % 10;
        n /= 10;
    }
    cout << (ans % 10 == 9);
    return 0;
}