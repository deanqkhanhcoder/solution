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
    vector<int> len(n);
    for (int i = 0; i < n; ++i){
        int idx = upper_bound(all(a), a[i] + k) - a.begin() - i;
        len[i] = idx;
    }
    vector<int> max_suff(n);
    max_suff[n - 1] = len[n - 1];
    for (int i = n - 2; i >= 0; --i){
        max_suff[i] = max(max_suff[i + 1], len[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int val = ((i + len[i] == n) ? 0 : max_suff[i + len[i]]);
        ans = max(ans, len[i] + val);
    }
    cout << ans;
    return 0;
}