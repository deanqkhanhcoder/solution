#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int q; cin >> q;
    while (q--){
        int a, b; cin >> a >> b;
        while (b > a){
            if (b % 2 == 0){
                b /= 2;
            } else {
                if (b % 10 == 1){
                    b /= 10;
                } else {
                    break;
                }
            }
        }
        cout << (b == a ? "YES\n" : "NO\n");
    }
    return 0;
}