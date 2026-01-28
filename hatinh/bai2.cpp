#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int LIMIT = (int)1e6;
int main(){
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n), k(n);
    for (int i = 0; i < n; ++i){
        int ai, bi, ki;
        cin >> ai >> bi >> ki;
        a[i] = ai;
        b[i] = bi;
        k[i] = ki;
    }
    vector<int> cnt(LIMIT, 0);
    for (int i = 2; i <= LIMIT; ++i){
        if (cnt[i] == 0){
            for (int j = i; j <= LIMIT; j += i){
                cnt[j]++;
            }
        }
    }
    cout << cnt[26] << endl;
    cout << cnt[28] << endl;
    cout << cnt[30] << endl;
}