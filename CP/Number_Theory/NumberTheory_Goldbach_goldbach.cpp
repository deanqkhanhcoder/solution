#include <iostream>
using namespace std;
using ll = long long;

bool nt(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for (int p1 = 2; p1 * 2 <= n; ++p1) {
            int p2 = n - p1;
            if (nt(p1) && nt(p2)){
                cout << p1 << ' ' << p2 << endl;
            }
        }
    }
    return 0;
}