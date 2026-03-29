#include <iostream>
using namespace std;
using ll = long long;

ll tohop(int n, int k){
    if (k == 0 || k == n){
        return 1;
    }
    return tohop(n - 1,k - 1) + tohop(n - 1, k);
}


int main() {
    int n, k;
    cin >> n >> k;
    cout << tohop(n, k) << endl;
    return 0;
}