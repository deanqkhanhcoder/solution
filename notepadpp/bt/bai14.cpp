#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n <= 1){
        cout << -1;
        return 0;
    }
    if (n % 2 == 0) {
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2; ++i)
            cout << 2 << ' ';
    } else {
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2 - 1; ++i)
            cout << 2 << ' ';
        cout << 3 << ' ';
    }
    return 0;
}

