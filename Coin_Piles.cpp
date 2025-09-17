#include <iostream>
#include <cmath>
using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    int t; cin >> t;
    while (t--){
        int a; int b; cin >> a >> b;
        if ((0LL + a + b) % 3 == 0 && max(a, b) <= 2LL * min(a, b)){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}