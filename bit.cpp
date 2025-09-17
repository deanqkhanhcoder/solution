#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    FastIO();
    int n; cin >> n;
    ll a = 2, res = 1;
    while (n > 0){
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    cout << res;
}