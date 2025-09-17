#include <iostream>
using namespace std;
using ll = long long;

ll binBow(ll a, ll b){
    ll res = 1;
    while (b > 0){
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
int main(){
    ll a, b; cin >> a >> b;
    cout << binBow(a, b);
    return 0;
}