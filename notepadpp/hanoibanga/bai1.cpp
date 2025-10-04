#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, s, t; cin >> x >> s >> t;
    int l = (t - 1) % (x + s) + 1;
    cout << (l <= x);
}