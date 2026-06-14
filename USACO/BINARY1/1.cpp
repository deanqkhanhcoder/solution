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
    #define TASK "haybales"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    auto get = [&](int l, int r){
      int upper = upper_bound(all(a), r) - a.begin();
      int lower = lower_bound(all(a), l) - a.begin();
      return upper - lower;  
    };
    while(q--){
        int l, r; cin >> l >> r;
        cout << get(l, r) << endl;
    }
    return 0;
}