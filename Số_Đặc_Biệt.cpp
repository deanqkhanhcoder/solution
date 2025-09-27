#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    gp_hash_table<int,int> mp;
    for (int x : a) mp[x]++;

    vector<int> ans;
    ans.reserve(n);
    for (int x : a) if (mp[x] == 1) ans.push_back(x);

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << "\n";
}
