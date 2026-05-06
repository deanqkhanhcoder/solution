#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     freopen("paint.in", "r", stdin);
     freopen("paint.out", "w", stdout);
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (d < a || b < c){
        cout << b - a + d - c;
        return 0;
    } else {
        int l = min(a, c);
        int r = max(b, d);
        cout << r - l;
        return 0;
    }
}