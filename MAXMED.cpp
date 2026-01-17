#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    int mid = n / 2;
    for (int i = 1; i < n; ++i){
        ll dif = (a[i + mid] - a[i + mid - 1]) * i;
        if (k >= dif){
            k -= dif;
        } else {
            cout << a[i + mid - 1] + k / i;
            return 0;
        }
    }
    cout << a[n - 1] + k/mid;
    return 0;
}