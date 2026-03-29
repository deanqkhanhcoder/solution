#include <iostream>
using namespace std;
using ll = long long;

ll gt(int n){
    if (n <= 1) return 1;
    return 1ll * n * gt(n - 1);
}

int main() {
    int t;
    cin >> t;
    while(--t){
        int n; cin >> n;
        cout << gt(n) << endl;
    }
    return 0;
}
