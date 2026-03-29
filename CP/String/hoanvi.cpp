#include <iostream>
using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dapan(int n){
    if (n == 1){
        cout << 1;
        return;
    }
    if (n <= 3){
        cout << "NO SOLUTION";
        return;
    }
    for (int i = 2; i <= n; i += 2) cout << i << ' ';
    for (int i = 1; i <= n; i += 2) cout << i << ' ';
}
int main(){
    FastIO();
    int n; cin >> n;
    dapan(n);
    return 0;
}