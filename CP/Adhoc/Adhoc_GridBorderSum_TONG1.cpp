#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n; cin >> m >> n;
    int ans = 0;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            int a; cin >> a;
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
                ans += a;
                continue;
            }
        }
    }
    cout << ans;
}