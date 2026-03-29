#include <iostream>
using namespace std;
using ll = long long;

int ngichdao(ll n){
    ll rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}
int main(){
    ll n; cin >> n;
    cout << ngichdao(n) << endl;
    return 0;
}