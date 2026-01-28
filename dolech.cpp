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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = (int)a.size();
    const int LIMIT = a.back();
    int ans = 0;
    for (int i = 0; i < m; ++i){
        int fi = a[i];
        if (fi == 0 || fi == 1) continue;
        for (int j = 2*fi; j <= LIMIT; j += fi){
            int idx = lower_bound(a.begin(), a.end(), j - 1) - a.begin();
            if (idx == 0) continue;
            idx--;
            int se = a[idx];
            ans = max(ans, se % fi);
        }
        ans = max(ans, LIMIT % fi);
    }
    cout << ans;
    return 0;
}