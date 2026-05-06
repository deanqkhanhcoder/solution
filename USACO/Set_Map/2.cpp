#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<vector<int>> freq(n + 1);
    for (int i = 0; i < n; ++i){
        int x = a[i];
        freq[x].push_back(i);
    }
    vector<int> pref(n);
    unordered_set<int> d;
    for (int i = 0; i < n; ++i){
        int x = a[i];
        d.insert(x);
        pref[i] = (int)d.size();
    }
    ll ans = 0;
    for (int num = 1; num <= n; ++num){
        if (freq[num].empty()) continue;
        int sz = (int)freq[num].size();
        if (sz >= 2){
            int pos = freq[num][sz - 2];
            int way = (pos - 1 >= 0 ? pref[pos - 1] : 0);
            ans += way;
            if (sz > 2) ans--;
        }
    }
    cout << ans;
}