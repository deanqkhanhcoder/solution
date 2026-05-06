#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    unordered_map<int, int> mp;
    mp.reserve(2 * n);
    mp.max_load_factor(0.7);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        mp[a]++;
    }
    
    for (int &e : b) cin >> e;
    for (int &e : c) cin >> e;
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        int pos = c[i];
        ans += mp[b[pos - 1]];
    }
    cout << ans << endl;
    return 0;
}