#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, m; cin >> n >> m;
    int limit1 = (n - 1) / 3 + 1;
    int limit2 = (n - 2) / 3 + 1;
    if (m <= limit1){
        cout << 1 + (m - 1) * 3;
        return 0;
    }
    m -= limit1;
    if (m <= limit2){
        cout << 2 + (m - 1) * 3;
        return 0;
    }
    m -= limit2;
    cout << 3 + (m - 1) * 3;
    return 0;
}