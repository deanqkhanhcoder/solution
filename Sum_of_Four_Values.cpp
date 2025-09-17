#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    int a[n];
    for (int &p : a) cin >> p;
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            mp[a[i] + a[j]] = {i, j};

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            int need = x - a[i] - a[j];
            if (mp.count(need)) {
                int k = mp[need].first, l = mp[need].second;
                if (j < k) {
                    cout << i+1 << ' ' << j+1 << ' ' << k+1 << ' ' << l+1;
                    return 0;
                }
            }
        }
    cout << "IMPOSSIBLE";
    return 0; 
}