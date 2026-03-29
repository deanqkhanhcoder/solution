#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(abs(x1-x2), abs(y1-y2));
}