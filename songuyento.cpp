#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;

bool nguyento(ll n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void ptts(int n){
    for (ll i = 2; i * i <= n; i++){
        while (n % i == 0){
            cout << i << ' ';
            n /= i;
        }
    }
    if (n > 1) cout << n;
}
int main(){
    ll n; cin >> n;
    ptts(n);
    return 0;
}