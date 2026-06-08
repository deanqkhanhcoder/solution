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
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    // code here
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    vector<int> ans(n);
    int l = 0;
    for (int r = 0; r < n; ++r){
        while(l < r && a[r] - a[l] > k) l++;
        ans[r] = r - l + 1;
    }
    int max1 = 0;
    int max2 = 0;
    for (int i = 0; i < n; ++i){
        if (ans[i] > max1){
            max2 = max1;
            max1 = ans[i];
        } else if (ans[i] > max2){
            max2 = ans[i];
        }
    }
    cout << max1 + max2 << endl;
    // vector<int> max_suff(n);
    // max_suff[n - 1] = ans[n - 1];
    // for (int i = n - 2; i >= 0; i--){
    //     max_suff[i] = max(max_suff[i + 1], ans[i]);
    // }
    return 0;
}