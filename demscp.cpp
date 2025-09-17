#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ll l, r;
    cin >> l >> r;

    ll left = (ll)ceil(sqrt((long double)l));
    ll right = (ll)sqrt((long double)r);

    cout << right - left + 1;
    return 0;
}
