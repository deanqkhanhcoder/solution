#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int s; cin >> s;
    vector<int> v;
    v.reserve(n * m);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            int a; cin >> a;
            if (a < s) v.push_back(a);
        }
    }
    if (v.size() < 2){
        cout << -1;
        return 0;
    }
    sort(v.begin(), v.end());
    int l = 0, r = (int)v.size() - 1;
    int ans = -1;
    while (l < r){
        int sum = v[l] + v[r];
        if (sum < s){
            ans = max(ans, sum);
            ++l;
        } else {
            --r;
        }
    }
    cout << ans;
    return 0;
}
