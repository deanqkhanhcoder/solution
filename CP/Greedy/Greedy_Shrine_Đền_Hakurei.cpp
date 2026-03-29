#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ; cin >> n;
    int a = 1, b = 2, c = 4, d = 7;
    if (n == 1){
        cout << 1;
        return 0;
    } else if (n == 2){
        cout << 2;
        return 0;
    } else if (n == 3){
        cout << 4;
        return 0;
    } else if (n == 4){
        cout << 7;
        return 0;
    } else {
        for (int i = 5; i <= n; ++i){
            a = b;
            b = c;
            c = d;
            d = ((ll)a + b + c) % MOD;
        }
    }
    cout << d;
    return 0;
}