#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CANDIES.INP", "r", stdin);
    freopen("CANDIES.OUT", "w", stdout);
    int n; cin >> n;
    int c = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        if (a % 3 == 0 && a != 0){
            c++;
            ans += a;
        }
    }
    cout << c << endl;
    cout << (ans - c * 3)/3;
    return 0;
}