#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int slw = 0, ans = 0;
    for (int r = 0, l = 0; r < n; ++r){
        slw += a[r];
        while (slw > x && l <= r){
            slw -= a[l];
            l++;
        }
        if (slw == x) ans++;
    }
    cout << ans;
    return 0;
}