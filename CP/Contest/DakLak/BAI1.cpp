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
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    vector<int> row(n), col(n);
    for (int i = 0; i < n; ++i){
        int sum = 0;
        for (int j = 0; j < n; ++j){
            sum += a[i][j];
        }
        row[i] = sum;
    }
    for (int j = 0; j < n; ++j){
        int sum = 0;
        for (int i = 0; i < n; ++i){
            sum += a[i][j];
        }
        col[j] = sum;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (row[i] == col[j]) ans++;
        }
    }
    cout << ans;
    return 0;
}
