#include <iostream>
#include <algorithm> // để dùng __gcd
using namespace std;
#define gcd __gcd

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    FastIO();
    int n;
    cin >> n;
    int x;
    int g = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        g = gcd(g, x);
    }
    cout << g << '\n';
    return 0;
}