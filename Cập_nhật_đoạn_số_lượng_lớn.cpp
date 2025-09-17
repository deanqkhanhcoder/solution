#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q, m;
    cin >> n >> q >> m;
    vector<pair<int, int>> qe(q+1);
    for (int i = 1; i <= q; i++) {
        cin >> qe[i].first >> qe[i].second;
    }
    
    vector<int> f(q+2, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        f[x] += 1;
        f[y+1] -= 1;
    }
    
    for (int i = 1; i <= q; i++) {
        f[i] += f[i-1];
    }
    
    vector<int> diff(n+2, 0);
    for (int i = 1; i <= q; i++) {
        int l = qe[i].first;
        int r = qe[i].second;
        diff[l] += f[i];
        diff[r+1] -= f[i];
    }
    
    vector<int> A(n+1, 0);
    for (int i = 1; i <= n; i++) {
        A[i] = A[i-1] + diff[i];
        cout << A[i] << " ";
    } 
    return 0;
}