#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;

int demuoc(ll n){
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            cnt++;
            if (n / i != i){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ll n;
    cin >> n;
    cout << demuoc(n);
    return 0;
}
