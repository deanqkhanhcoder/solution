#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        long long y, x; cin >> y >> x;
        long long n = max(y, x);
        if (n % 2 == 1){
            if (x == n){
                cout << n*n - y + 1 << '\n';
            } else {
                cout << (n - 1)*(n - 1) + x << '\n';
            }
        } else {
            if (y == n){
                cout << n*n - x + 1 << '\n';
            } else {
                cout << (n - 1)*(n - 1) + y << '\n';
            }
        }
    }
    return 0;
}