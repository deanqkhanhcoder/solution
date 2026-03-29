#include <iostream>
#include <cmath>
using namespace std;
using int128 = __int128;

bool sqtrc(int128 x) {
    long double s = sqrtl((long double)x);
    int128 r = (int128)s;
    return r * r == x || (r + 1) * (r + 1) == x;
}

bool isfib(unsigned long long n) {
    int128 x = n;
    return sqtrc(5 * x * x + 4) || sqtrc(5 * x * x - 4);
}

int main() {
    int n;
    cin >> n;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        unsigned long long x;
        cin >> x;
        if (isfib(x)) {
            cout << x << " ";
            found = true;
        }
    }
    if (!found) cout << "NONE";
    return 0;
}
