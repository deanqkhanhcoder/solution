#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("AODAI.INP", "r", stdin);
    freopen("AODAI.OUT", "w", stdout);
    int n; cin >> n;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0; i < n; ++i){
        int s; cin >> s;
        if (s == 1) c1++;
        else if (s == 2) c2++;
        else if (s == 3) c3++;
        else c4++;
    }
    int ans = 0;
    ans += c4;
    ans += c3;
    c1 = max(0, c1 - c3);
    ans += c2 / 2;
    if (c2 % 2 == 1){
        ans++;
        c1 = max(0, c1 - 2);
    }
    if (c1 > 0) ans += (c1 + 3) / 4;
    cout << ans;
    return 0;
}