#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
    int q; cin >> q;
    while (q--){
        ll k; cin >> k;
        int d; ll base = 1;
        for (d = 1; ; ++d){
            ll count = 9LL * base * d;
            if (k > count) {
                k -= count;
                base *= 10;
            } else {
                break;
            }
            /*
            ll offset = (k - 1) / d; 
            ll num = base + offset; 
            int index = (k - 1) % d; 
            string s = to_string(num); 
            cout << s[index] << "\n";
            */
            }
            cout << ((base + (k - 1) / d) / (ll)pow(10, d - 1 - (k - 1) % d) % 10) << "\n";
        }
    return 0;
}
