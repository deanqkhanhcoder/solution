#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end(), greater<int>());
    if (a[0] == 0){
        cout << 0;
        return 0;
    }
    int i;
    for (i = 1; i <= n; ++i){
        if (i + 1 > a[i]) break;
    }
    cout << i;
    return 0;
}