#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = (int)1e6 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> d(MAX_N, 0);
    for (int i = 1; i < MAX_N; ++i){
        for (int j = i; j < MAX_N; j += i){
            d[j]++;
        }
        d[i] += d[i - 1];
    }
    while (n--){
        int l, r; cin >> l >> r;
        cout << d[r] - d[l - 1] << "\n";
    }
    return 0;
}